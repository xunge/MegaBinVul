#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define L_HORIZ 1
#define L_VERT 2
#define FALSE 0
#define TRUE 1

typedef int l_int32;
typedef struct Sel SEL;
typedef struct Sela SELA;

#define ERROR_PTR(msg, proc, ret) (ret)
#define PROCNAME(name)
#define stringNew(str) strdup(str)

extern l_int32 selaGetCount(SELA *sela);
extern SEL *selaGetSel(SELA *sela, l_int32 index);
extern void selGetParameters(SEL *sel, l_int32 *psy, l_int32 *psx, l_int32 *pcy, l_int32 *pcx);
extern char *selGetName(SEL *sel);