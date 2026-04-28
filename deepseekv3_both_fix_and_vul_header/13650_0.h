#include <stdio.h>
#include <stdint.h>

#define CLI_ROL(val, shift) ((val) << (shift)) | ((val) >> (8 - (shift)))
#define CLI_ROR(val, shift) ((val) >> (shift)) | ((val) << (8 - (shift)))

void cli_dbgmsg(const char *format, ...);