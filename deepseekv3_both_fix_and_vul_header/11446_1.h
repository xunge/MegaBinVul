#include <stdio.h>
#include <stddef.h>

typedef unsigned char u8;

typedef struct sc_path {
    unsigned int type;
    unsigned char value[16];
    size_t len;
} sc_path_t;

typedef struct sc_file {
    size_t size;
} sc_file_t;

typedef struct RSA_st RSA;

extern int opt_key_num;
extern void *card;
extern int select_app_df(void);
extern void sc_format_path(const char *, sc_path_t *);
extern int sc_select_file(void *card, sc_path_t *path, sc_file_t **file);
extern void sc_file_free(sc_file_t *file);
extern int sc_read_binary(void *card, unsigned int offset, unsigned char *buf, size_t count, unsigned int flags);
extern const char *sc_strerror(int errnum);
extern int parse_public_key(unsigned char *p, size_t keysize, RSA *rsa);