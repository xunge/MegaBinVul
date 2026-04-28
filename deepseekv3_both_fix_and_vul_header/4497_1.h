#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define HEADER_SIZE 4
#define ASN1_CHUNK_INITIAL_SIZE (16 * 1024)

typedef struct bio_st BIO;
typedef struct buf_mem_st BUF_MEM;

struct buf_mem_st {
    size_t length;
    char *data;
};

BUF_MEM *BUF_MEM_new(void);
void BUF_MEM_free(BUF_MEM *a);
int BUF_MEM_grow_clean(BUF_MEM *str, size_t len);
int BIO_read(BIO *b, void *data, int len);

#define ASN1_F_ASN1_D2I_READ_BIO 0
#define ASN1_R_NOT_ENOUGH_DATA 0
#define ASN1_R_TOO_LONG 0
#define ASN1_R_HEADER_TOO_LONG 0
#define V_ASN1_EOC 0
#define ERR_R_MALLOC_FAILURE 0

void ASN1err(int f, int r);
void ERR_clear_error(void);
unsigned long ERR_peek_error(void);
unsigned long ERR_GET_REASON(unsigned long e);
int ASN1_get_object(const unsigned char **pp, long *plength, int *ptag, int *pclass, int omax);