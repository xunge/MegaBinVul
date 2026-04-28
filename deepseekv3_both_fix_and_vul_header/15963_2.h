#include <string.h>

#define AUTH_VECTOR_LEN 16
#define AUTH_PASS_LEN 16
#define MAXPASS 128
#define PW_PASSWORD 1
#define PW_OLD_PASSWORD 2

typedef struct {
    unsigned long state[4];
    unsigned long count[2];
    unsigned char buffer[64];
} MD5_CTX;

typedef struct {
    int type;
    unsigned char *data;
} attribute_t;

typedef struct {
    unsigned char vector[AUTH_VECTOR_LEN];
} AUTH_HDR;

#define CONST const

void MD5Init(MD5_CTX *context);
void MD5Update(MD5_CTX *context, unsigned char *input, unsigned int inputLen);
void MD5Final(unsigned char digest[16], MD5_CTX *context);
attribute_t *find_attribute(AUTH_HDR *request, int type);
void add_attribute(AUTH_HDR *request, int type, unsigned char *data, int length);
void xor(unsigned char *output, unsigned char *input, int len);