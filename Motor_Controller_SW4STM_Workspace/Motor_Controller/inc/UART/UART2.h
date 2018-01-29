#ifndef UART2_H
#define UART2_H

#define UART2_RX_BUFF_SIZE 20
#define UART2_TX_BUFF_SIZE 20

#include "stdint.h"

void uart2_init(uint32_t p_baud_rate);
char uart2_read();
int  uart2_available();
void uart2_write(char p_data);
void uart2_write_string(char* p_string);


#endif //UART2_H