#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define FALSE 0
#define TRUE 1

typedef int32_t linenr_T;
#define MAXLNUM INT32_MAX

#define FAIL 1
#define OK 0

#define BLN_DUMMY 0x01
#define READ_NEW 0x01
#define READ_DUMMY 0x02

typedef struct buf_T buf_T;
typedef struct exarg_T exarg_T;
typedef struct aco_save_T aco_save_T;

struct buf_T {
    char *b_ffname;
    char *b_fname;
    struct {
        linenr_T ml_line_count;
    } b_ml;
};

struct exarg_T {
    char *cmd;
};

struct aco_save_T {
    // Placeholder for actual fields
};

extern buf_T *curbuf;

buf_T *buflist_new(char *ffname, char *fname, linenr_T lnum, int flags);
int prep_exarg(exarg_T *eap, buf_T *buf);
void wipe_buffer(buf_T *buf, int force);
void aucmd_prepbuf(aco_save_T *aco, buf_T *buf);
int ml_open(buf_T *buf);
int readfile(char *fname, char *sfname, linenr_T from, linenr_T lines, linenr_T to, exarg_T *eap, int flags);
char *ml_get_buf(buf_T *buf, linenr_T lnum, int will_change);
char *ml_get(linenr_T lnum);
void aucmd_restbuf(aco_save_T *aco);
void vim_free(void *ptr);

#define STRCMP strcmp