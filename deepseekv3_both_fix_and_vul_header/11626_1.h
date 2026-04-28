#include <stdio.h>

struct pt_regs {
    unsigned long ip;
    unsigned int cs;
};

typedef unsigned char u8;

void show_opcodes(u8 *ip, const char *loglvl);