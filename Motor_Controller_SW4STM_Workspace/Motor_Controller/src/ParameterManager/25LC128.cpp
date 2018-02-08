#include "../../inc/ParameterManager/25LC128.h"
#include "stm32f4xx_spi.h"

//Prototypes
uint8_t spi_send(uint8_t data);
uint8_t readStatusRegister_25LC128(void);
void writeEnable_25LC128(void);
void modBlockProtection_25LC128(uint8_t p_protection);


void eeprom_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  SPI_InitTypeDef SPI_InitStruct;
  
  // enable clock for used IO pins
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  
  /* configure pins used by SPI2
   * PB13 = SCK
   * PB14 = MISO
   * PB15 = MOSI
   */
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  // connect SPI1 pins to SPI alternate function
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_SPI2);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_SPI2);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI2);
  
  /* Configure the chip select pin
     in this case we will use PB12 */
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  CHIP_DESELECT;
  
  // enable peripheral clock
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
  
  /* configure SPI2 in Mode 0
   * CPOL = 0 --> clock is low when idle
   * CPHA = 0 --> data is sampled at the first edge
   */
  SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex; // set to full duplex mode, seperate MOSI and MISO lines
  SPI_InitStruct.SPI_Mode = SPI_Mode_Master;     // transmit in master mode, NSS pin has to be always high
  SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b; // one packet of data is 8 bits wide
  SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;        // clock is low when idle
  SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;      // data sampled at first edge
  SPI_InitStruct.SPI_NSS = SPI_NSS_Soft | SPI_NSSInternalSoft_Set; // set the NSS management to internal and pull internal NSS high
  SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; // SPI frequency is APB1 frequency / 4
  SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;// data is transmitted MSB first
  SPI_Init(SPI2, &SPI_InitStruct);
  
  SPI_Cmd(SPI2, ENABLE); // enable SPI1

  
  modBlockProtection_25LC128(0x00);
}

uint8_t spi_send(uint8_t data){

	SPI1->DR = data; // write data to be transmitted to the SPI data register
	while( !(SPI1->SR & SPI_I2S_FLAG_TXE) ); // wait until transmit complete
	while( !(SPI1->SR & SPI_I2S_FLAG_RXNE) ); // wait until receive complete
	while( SPI1->SR & SPI_I2S_FLAG_BSY ); // wait until SPI is not busy anymore
	return SPI1->DR; // return received data from SPI data register
}


uint8_t readStatusRegister_25LC128(void)
{
  CHIP_SELECT;
  
  spi_send(RDSR);
  uint8_t sr = spi_send(0x00);
  
  CHIP_DESELECT;
  
  return sr;
}

void writeEnable_25LC128(void)
{
  CHIP_SELECT;
  spi_send(WREN);
  CHIP_DESELECT;
}

void writeDisable_25LC128(void)
{
  CHIP_SELECT;
  spi_send(WRDI);
  CHIP_DESELECT;
}

void modBlockProtection_25LC128(uint8_t p_protection)
{
  if (p_protection > 3) return;
  
  CHIP_SELECT;
  spi_send(WRSR);
  spi_send(p_protection << 2);
  CHIP_DESELECT;
}

char LireMemoireEEPROM(unsigned int AdresseEEPROM, unsigned int NbreOctets, unsigned char* Destination)
{
  if(AdresseEEPROM >= NUMBER_OF_BYTES) return 1;
  if((AdresseEEPROM + NbreOctets) > NUMBER_OF_BYTES) return 1;
  
  CHIP_SELECT;
  
  spi_send(READ);
  spi_send((uint8_t)(AdresseEEPROM >> 8));
  spi_send((uint8_t) AdresseEEPROM);
  
  uint32_t i;
  for(i = NbreOctets; i != 0; i--)
  {
    *Destination = spi_send(0x00);
    Destination++;
  }
  
  CHIP_DESELECT;
  
  return 0;
}
char EcrireMemoireEEPROM(unsigned int AdresseEEPROM, unsigned int NbreOctets, unsigned char* Source)
{
  uint32_t endAdressOfCurrentPage;
  uint32_t remainingBytesUntilEndOfPage;
  
  if(AdresseEEPROM >= NUMBER_OF_BYTES) return 1;
  if((AdresseEEPROM + NbreOctets) > NUMBER_OF_BYTES) return 1;
  
branch:

  endAdressOfCurrentPage = ((AdresseEEPROM / BYTES_PER_PAGE) * BYTES_PER_PAGE) + 63;
  remainingBytesUntilEndOfPage = (endAdressOfCurrentPage - AdresseEEPROM) + 1;
  
  while(readStatusRegister_25LC128() & WIP);
  
  writeEnable_25LC128();
  
  CHIP_SELECT;
    
  spi_send(WRITE);
  spi_send((uint8_t)(AdresseEEPROM >> 8));
  spi_send((uint8_t) AdresseEEPROM);
  
  if(NbreOctets > remainingBytesUntilEndOfPage)
  {
    for(uint32_t i = remainingBytesUntilEndOfPage; i != 0; i--)
    {
      spi_send(*Source);
      Source++;
    }
    
    CHIP_DESELECT;
    
    NbreOctets -= remainingBytesUntilEndOfPage;
    AdresseEEPROM += remainingBytesUntilEndOfPage;
   
    goto branch;
  }
  else
  {
    for(uint32_t i = NbreOctets; i != 0; i--)
    {
      spi_send(*Source);
      Source++;
    }
    
    CHIP_DESELECT;
  }
 
  while(readStatusRegister_25LC128() & WIP);
  
  return 0;
}



