#include <stdbool.h>
#include <stddef.h>

#define FALSE false
#define TRUE true

typedef unsigned char BYTE;
typedef bool BOOL;

typedef struct rdpRdp rdpRdp;
struct rdpRdp {
    void* fips_decrypt;
};

extern bool winpr_Cipher_Update(void* cipher, BYTE* input, size_t ilen, BYTE* output, size_t* olen);