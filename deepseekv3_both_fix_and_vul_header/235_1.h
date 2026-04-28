#include <stdio.h>
#include <stdbool.h>

#define NSCRIPT 10
#define MAXPATHL 1024
#define FAIL 1
#define TRUE 1
#define FALSE 0
#define READBIN "rb"
#define NORMAL 0

typedef unsigned char char_u;

struct oparg_S {
    // Add necessary fields for oparg_T structure
    int dummy; // placeholder for actual fields
};
typedef struct oparg_S oparg_T;

extern char_u *NameBuff;
extern int curscript;
extern FILE *scriptin[NSCRIPT];
extern int State;
extern int restart_edit;
extern int p_im;
extern int finish_op;
extern int msg_scroll;
extern bool ignore_script;

const char *e_nesting = "E103: Too many nested script files";
const char *e_notopen = "E484: Can't open file %s";

#define _(x) x

void emsg(const char *);
void semsg(const char *, char_u *);
void expand_env(char_u *, char_u *, int);
FILE *mch_fopen(char *, const char *);
int save_typebuf(void);
void clear_oparg(oparg_T *);
void normal_cmd(oparg_T *, int);
int vpeekc(void);
void update_topline_cursor(void);