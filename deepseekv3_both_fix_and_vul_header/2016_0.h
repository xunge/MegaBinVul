#include <string.h>

#define FAC_NATIONAL_RAND      0x40
#define FAC_NATIONAL_DEST_DIGI 0x80
#define FAC_NATIONAL_SRC_DIGI  0x81
#define FAC_NATIONAL_FAIL_CALL 0x82
#define FAC_NATIONAL_FAIL_ADD  0x83
#define FAC_NATIONAL_DIGIS     0x84

#define AX25_ADDR_LEN 7
#define ROSE_ADDR_LEN 5
#define ROSE_MAX_DIGIS 8
#define AX25_HBIT     0x80

struct rose_facilities_struct {
    unsigned int rand;
    unsigned char source_digis[ROSE_MAX_DIGIS][AX25_ADDR_LEN];
    unsigned char dest_digis[ROSE_MAX_DIGIS][AX25_ADDR_LEN];
    unsigned char fail_call[AX25_ADDR_LEN];
    unsigned char fail_addr[ROSE_ADDR_LEN];
    unsigned char source_ndigis;
    unsigned char dest_ndigis;
};