#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PATH_MAX 4096

extern int Gflag;
extern time_t Gflag_time;

void error(const char *fmt, ...);