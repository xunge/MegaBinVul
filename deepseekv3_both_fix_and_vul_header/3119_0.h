#include <stdio.h>

#define clear 256

static int codesize;
static int codemask;
static int avail;
static int oldcode;
static unsigned char *stackp;
static unsigned char stack[4096];
static unsigned short prefix[4096];
static unsigned char suffix[4096];
static const int datasize = 8;