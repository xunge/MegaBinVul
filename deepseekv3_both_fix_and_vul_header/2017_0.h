#include <string.h>

#define FAC_CCITT_DEST_NSAP 0xC0
#define FAC_CCITT_SRC_NSAP  0xC1
#define ROSE_ADDR_LEN 5

struct rose_facilities_struct {
    unsigned char source_addr[ROSE_ADDR_LEN];
    unsigned char dest_addr[ROSE_ADDR_LEN];
    char source_call[11];
    char dest_call[11];
};

extern void asc2ax(char *ax25, const char *asc);