#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NSCRIPT 10
#define MAXPATHL 1024
#define TRUE 1
#define FALSE 0
#define kFileReadOnly 0
#define NORMAL 0

typedef unsigned char char_u;

typedef struct {
    // oparg_T members would go here
} oparg_T;

extern char_u *NameBuff;
extern int curscript;
extern FILE *scriptin[NSCRIPT];
extern int ignore_script;
extern int State;
extern int restart_edit;
extern int p_im;
extern int finish_op;
extern int msg_scroll;

void EMSG(const char *msg);
void emsgf(const char *fmt, ...);
char *os_strerror(int errnum);
void expand_env(char_u *name, char_u *buff, int len);
FILE *file_open_new(int *error, char *name, int mode, int perm);
void save_typebuf(void);
void update_topline_cursor(void);
void normal_cmd(oparg_T *oap, int forceit);
int vpeekc(void);
void clear_oparg(oparg_T *oap);
const char *_(const char *str);

const char *e_nesting = "Too many nested scripts";
const char *e_notopen_2 = "Cannot open file %s: %s";