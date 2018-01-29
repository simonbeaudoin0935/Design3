#ifndef UART3_H
#define UART3_H

#define UART3_RX_BUFF_SIZE 20
#define UART3_TX_BUFF_SIZE 20

#include "stdint.h"

void uart3_init(uint32_t p_baud_rate);
char uart3_read();
int  uart3_available();
void uart3_write(char p_data);
void uart3_write_string(char* p_string);


#endif //UART2_H