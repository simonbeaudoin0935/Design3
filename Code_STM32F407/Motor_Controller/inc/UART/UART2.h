#ifndef UART2_H
#define UART2_H

#define UART2_RX_BUFF_SIZE 100
#define UART2_TX_BUFF_SIZE 100


void UART2_init(unsigned int p_baud_rate);
char UART2_read();
int  UART2_available();
void UART2_write(char p_data);
void UART2_print(char* p_string);

void UART2_writeFloatUnion(float p_float);
void UART2_writeIntegerUnion(int p_integer);


#endif //UART2_H
