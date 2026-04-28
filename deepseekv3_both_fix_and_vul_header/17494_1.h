#include <string.h>

#define __init __attribute__((__section__(".init.text")))
extern char __bss_start[];
extern char __bss_stop[];