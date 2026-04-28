#include <stdio.h>

#define MAX_LZW_BITS 12
#define FALSE 0
#define TRUE 1

typedef int gint;
typedef unsigned char guchar;

extern gint GetCode(FILE *fd, gint code_size, gint flag);
extern gint GetDataBlock(FILE *fd, guchar *buf);
extern gint ZeroDataBlock;
extern void gimp_quit(void);
extern void g_message(const char *format, ...);
extern void g_print(const char *format, ...);