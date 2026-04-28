#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bio_st BIO;
#define BIO_TYPE_CIPHER 0
#define CMS_TEXT 1
#define CMS_F_CMS_COPY_CONTENT 0
#define ERR_R_MALLOC_FAILURE 0
#define CMS_R_SMIME_TEXT_ERROR 0

struct bio_st {
    int type;
    int cipher_status;
};

static BIO* BIO_new(int type) { return calloc(1, sizeof(BIO)); }
static int BIO_s_null() { return 0; }
static int BIO_s_mem() { return 0; }
static void BIO_set_mem_eof_return(BIO *b, int v) {}
static int BIO_read(BIO *b, void *buf, int len) { return 0; }
static int BIO_write(BIO *b, const void *buf, int len) { return len; }
static int BIO_method_type(BIO *b) { return b->type; }
static int BIO_get_cipher_status(BIO *b) { return b->cipher_status; }
static void BIO_free(BIO *b) { free(b); }
static int SMIME_text(BIO *in, BIO *out) { return 1; }
static void CMSerr(int f, int r) {}