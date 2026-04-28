#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

#ifndef HAVE_ARC4RANDOM_BUF
#define X_GETTIMEOFDAY(tv) gettimeofday(tv, NULL)
#endif