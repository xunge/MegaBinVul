#include <stdio.h>
#include <stddef.h>

typedef unsigned char u8;

struct sc_path {
    unsigned char value[16];
    size_t len;
};
typedef struct sc_path sc_path_t;

struct sc_acl_entry {
    int method;
};
typedef struct sc_acl_entry sc_acl_entry_t;

struct sc_file {
    size_t size;
    sc_acl_entry_t acl[16];
};
typedef struct sc_file sc_file_t;

#define SC_AC_OP_READ 0
#define SC_AC_NEVER 0

extern int opt_key_num;
extern void *card;

int select_app_df(void);
void sc_format_path(const char *, sc_path_t *);
int sc_select_file(void *, const sc_path_t *, sc_file_t **);
const sc_acl_entry_t *sc_file_get_acl_entry(const sc_file_t *, int);
void sc_file_free(sc_file_t *);
int sc_read_binary(void *, unsigned int, unsigned char *, size_t, int);
const char *sc_strerror(int);
int parse_private_key(const unsigned char *, size_t, void *);

struct RSA;
typedef struct RSA RSA;