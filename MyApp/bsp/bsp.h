#ifndef __BSP_BSP_H_
#define __BSP_BSP_H_

#include "hw_def.h"
#include <stdint.h>

void bspInit();
void delay(uint32_t ms);

uint32_t millis(void);

#endif // __BSP_BSP_H_