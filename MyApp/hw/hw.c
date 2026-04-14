#include "driver/cli.h"
#include "led.h"
#include "uart.h"
#include "hw_def.h"
#include "cli.h"
#include "hw.h"

void hwInit(void){
    ledInit();
    uartInit();
    cliInit();
}

