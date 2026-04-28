#include <stdarg.h>
#include <string.h>
#include <stddef.h>

typedef long long sf_count_t;

#define SF_FALSE 0
#define SF_TRUE 1

#define SF_ENDIAN_LITTLE 0x1234
#define SF_ENDIAN_BIG 0x4321

#define SFE_INTERNAL 1

typedef struct {
    unsigned char *ptr;
    sf_count_t indx;
    sf_count_t len;
} HEADER;

typedef struct {
    HEADER header;
    int rwf_endian;
    int error;
} SF_PRIVATE;

void header_put_marker(SF_PRIVATE *psf, unsigned int data);
void header_put_byte(SF_PRIVATE *psf, unsigned int data);
void header_put_be_short(SF_PRIVATE *psf, unsigned int data);
void header_put_le_short(SF_PRIVATE *psf, unsigned int data);
void header_put_be_3byte(SF_PRIVATE *psf, unsigned int data);
void header_put_le_3byte(SF_PRIVATE *psf, unsigned int data);
void header_put_be_int(SF_PRIVATE *psf, unsigned int data);
void header_put_le_int(SF_PRIVATE *psf, unsigned int data);
void header_put_be_8byte(SF_PRIVATE *psf, sf_count_t data);
void header_put_le_8byte(SF_PRIVATE *psf, sf_count_t data);
void float32_be_write(float data, unsigned char *ptr);
void float32_le_write(float data, unsigned char *ptr);
void double64_be_write(double data, unsigned char *ptr);
void double64_le_write(double data, unsigned char *ptr);
int psf_bump_header_allocation(SF_PRIVATE *psf, size_t size);
void psf_log_printf(SF_PRIVATE *psf, const char *format, ...);