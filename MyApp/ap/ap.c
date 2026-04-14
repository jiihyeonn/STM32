#include "hw_def.h"
#include "stm32f411xe.h"
#include "stm32f4xx_hal.h"
#include "uart.h"
#include "cli.h"
#include "hw.h"
#include "bsp.h"
#include <stdint.h>
#include <string.h>

void cliled(uint8_t argc, char **argv){
    if(argc == 2){
        if(strcmp(argv[1], "on") == 0){
            ledOn();
            cliPrintf("LED ON\r\n");
        }
        else if(strcmp(argv[1], "off") == 0){
            ledOff();
            cliPrintf("LED OFF\r\n");
        }
        else if(strcmp(argv[1], "toggle") == 0){
            ledToggle();
            cliPrintf("LED TOGGLE\r\n");
        }
        else{
            cliPrintf("Invaild Command\r\n");
        }
    }
    else{
        cliPrintf("Usage: led[on|off|toggle]\r\n");
    }
}

void cliInfo(uint8_t argc, char **argv) {
    if ((argc == 2) || strcmp(argv[1], "uptime") == 0) {
        cliPrintf("System Uptime: %d ms \r\n", millis());
    }
    else {
        cliPrintf("Usage: info[uptime]\r\n");
    }
}

void cliSys(uint8_t argc, char **argv) {
    if(argc == 2 && strcmp(argv[1], "reset") == 0){
        NVIC_SystemReset();
    }
    else {
        cliPrintf("Usage: sys[reset]\r\n");
    }
}

void apInit(void){
    hwInit();
    cliAdd("led", cliled);
    cliAdd("info", cliInfo);
    cliAdd("sys", cliSys);
}

void apMain(void){
    uartPrintf(0,"Hello World!\r\n");

    while(1){

        cliMain();

        // if(uartAvailable(0) > 0){
        //     uint8_t ch = uartRead(0);
            
        //     uartPrintf(0, "%c", ch);
        // }

        // ledOn();
        // HAL_Delay(1000);
        // ledOff();
        // HAL_Delay(1000);

        // uartWrite(0,(uint8_t *)"HELLOW", 7);
        // uartPrintf(0,"hello world%d\r\n",10);
    }
}