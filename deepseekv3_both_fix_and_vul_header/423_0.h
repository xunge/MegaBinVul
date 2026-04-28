#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FE_ABC 0
#define FE_FMT 1
#define FE_PS 2

struct {
    int abc_vers;
} parse;

static int latin;
static int state;
static int skip;
static char prefix[10];
static unsigned char *selection;
static int offset;

void get_vers(char *s);
void txt_add(unsigned char *s, int l);
void txt_add_eos(char *fname, int linenum);
void txt_add_cnv(unsigned char *s, int l, int flag);
void include_file(char *s);
int tune_select(unsigned char *s);
void abc_eof();