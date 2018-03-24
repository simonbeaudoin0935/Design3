#ifndef UART3_H
#define UART3_H

#define UART3_RX_BUFF_SIZE 100
#define UART3_TX_BUFF_SIZE 100


void UART3_init(unsigned int p_baud_rate);
char UART3_read();
int  UART3_available();
void UART3_write(char p_data);
void UART3_print(char* p_string);


#endif //UART2_H
