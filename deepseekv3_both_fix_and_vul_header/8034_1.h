#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef struct BZFILE BZFILE;

#define BZ_OK 0
#define BZ_STREAM_END 4

ssize_t offtin(u_char *buf);