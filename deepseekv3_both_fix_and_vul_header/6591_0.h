#include <stddef.h>
#include <string.h>

#define LTC_ARGCHK(cond) do { if (!(cond)) return CRYPT_INVALID_ARG; } while(0)
#define CRYPT_OK 0
#define CRYPT_PK_NOT_PRIVATE 1
#define CRYPT_PK_INVALID_TYPE 2
#define CRYPT_PK_INVALID_SIZE 3
#define CRYPT_BUFFER_OVERFLOW 4
#define CRYPT_ERROR 5
#define CRYPT_INVALID_ARG 6

#define PK_PRIVATE 0
#define PK_PUBLIC 1

#define LTC_MP_LT -1
#define LTC_MP_EQ 0

typedef struct {
    int type;
    void *N;
    void *e;
    void *d;
    void *p;
    void *q;
    void *dP;
    void *dQ;
    void *qP;
} rsa_key;

int mp_init_multi(void **a, ...);
int mp_read_unsigned_bin(void *a, unsigned char *b, int c);
int mp_cmp(void *a, void *b);
int mp_exptmod(void *a, void *b, void *c, void *d);
int mp_rand(void *a, int b);
int mp_invmod(void *a, void *b, void *c);
int mp_mulmod(void *a, void *b, void *c, void *d);
int mp_sub(void *a, void *b, void *c);
int mp_mul(void *a, void *b, void *c);
int mp_add(void *a, void *b, void *c);
int mp_get_digit_count(void *a);
unsigned long mp_unsigned_bin_size(void *a);
int mp_to_unsigned_bin(void *a, unsigned char *b);
void mp_clear_multi(void *a, ...);
void zeromem(void *a, unsigned long b);