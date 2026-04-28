#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1
#define FAIL -1
#define NUL '\0'
#define VAR_UNKNOWN 0
#define VAR_LIST 1
#define VAR_BLOB 2
#define APPENDBIN "ab"
#define WRITEBIN "wb"

typedef unsigned char char_u;

typedef struct typval_S typval_T;
typedef struct listitem_S listitem_T;
typedef struct list_S list_T;
typedef struct blob_S blob_T;

struct typval_S {
    int v_type;
    union {
        list_T *v_list;
        blob_T *v_blob;
        int v_number;
    } vval;
};

struct listitem_S {
    typval_T li_tv;
    listitem_T *li_next;
};

struct list_S {
    listitem_T *lv_first;
};

struct blob_S {
    char_u *data;
    size_t len;
};

extern int check_restricted(void);
extern int check_secure(void);
extern char_u *tv_get_string_chk(typval_T *);
extern char_u *vim_strchr(char_u *, int);
extern int write_blob(FILE *, blob_T *);
extern int write_list(FILE *, list_T *, int);
extern FILE *mch_fopen(char *, const char *);
extern void semsg(const char *, ...);
extern const char *_(const char *);
extern const char *e_invarg2;
extern const char *e_notcreate;
extern int p_fs;
extern int vim_ignored;