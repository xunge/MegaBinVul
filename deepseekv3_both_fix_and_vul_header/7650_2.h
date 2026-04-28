#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct X509 X509;
typedef struct X509_STORE X509_STORE;
typedef struct X509_STORE_CTX X509_STORE_CTX;
typedef struct X509_VERIFY_PARAM X509_VERIFY_PARAM;
typedef struct stack_st_X509 STACK_OF_X509;
#define STACK_OF(type) struct stack_st_##type

#define ERR_LIB_OCSP 39
#define ERR_R_MALLOC_FAILURE 64
#define ERR_R_X509_LIB 11
#define OCSP_R_CERTIFICATE_VERIFY_ERROR 100
#define OCSP_PARTIAL_CHAIN 0x0001
#define X509_V_FLAG_PARTIAL_CHAIN 0x80000
#define X509_V_FLAG_CRL_CHECK 0x40000
#define X509_PURPOSE_OCSP_HELPER 8
#define X509_TRUST_OCSP_REQUEST 9
#define NID_id_pkix_OCSP_noCheck 369

void ERR_raise(int lib, int reason);
void ERR_raise_data(int lib, int reason, const char *fmt, ...);
char *X509_verify_cert_error_string(int err);