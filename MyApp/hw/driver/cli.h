#ifndef ___HW__DRIVER__CLI_H__
#define ___HW__DRIVER__CLI_H__

#include "hw_def.h"
#include <stdint.h>
#include <stdbool.h>

void cliInit();
void cliMain();
void cliPrintf(const char *fmt, ...);

void cliParsArgs(char *line_buf);
bool cliAdd(const char *cmd_str, void (*cmd_func)(uint8_t argc, char **argv));
void cliRunCommand();

#endif // ___HW__DRIVER__CLI_H__