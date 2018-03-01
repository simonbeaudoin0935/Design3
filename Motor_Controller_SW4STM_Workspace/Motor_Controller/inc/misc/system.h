#ifndef MISC_SYSTEM_H_
#define MISC_SYSTEM_H_

#include "UART/UART2.h"
#include "UART/UART3.h"

extern volatile unsigned int g_systickCount;

void systemInit(void);

#endif /* MISC_SYSTEM_H_ */
