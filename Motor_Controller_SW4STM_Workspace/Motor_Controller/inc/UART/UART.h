#ifndef UART_UART_H_
#define UART_UART_H_



typedef enum{
	UART_1,
	UART_2,
	UART_3,
	UART_4
}UART;

void UART_init(UART p_uart, unsigned int p_baudRate);
char UART_read(UART p_uart);
int  UART_available(UART p_uart);
void UART_write(UART p_uart, char p_data);
void UART_print(UART p_uart, char* p_string);
void UART_println(UART p_uart, char* p_string);

void UART_writeFloatUnion(UART p_uart, float p_float);
void UART_writeIntegerUnion(UART p_uart, int p_integer);

#endif /* UART_UART_H_ */
