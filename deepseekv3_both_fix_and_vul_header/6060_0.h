#include <string.h>

typedef struct mbedtls_x509_buf {
    int len;
    unsigned char *p;
} mbedtls_x509_buf;

typedef struct mbedtls_x509_time {
    int year, mon, day;
    int hour, min, sec;
} mbedtls_x509_time;

typedef struct mbedtls_x509_crl_entry {
    mbedtls_x509_buf serial;
    mbedtls_x509_time revocation_date;
    struct mbedtls_x509_crl_entry *next;
} mbedtls_x509_crl_entry;

typedef struct mbedtls_x509_crl {
    mbedtls_x509_crl_entry entry;
} mbedtls_x509_crl;

typedef struct mbedtls_x509_crt {
    mbedtls_x509_buf serial;
} mbedtls_x509_crt;

int mbedtls_x509_time_is_past( const mbedtls_x509_time *time );