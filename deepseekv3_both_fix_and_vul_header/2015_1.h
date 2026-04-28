#include <stdio.h>

#define FAC_NATIONAL 0
#define FAC_CCITT 1
#define KERN_DEBUG ""

struct rose_facilities_struct;

int rose_parse_national(unsigned char *p, struct rose_facilities_struct *facilities, int len);
int rose_parse_ccitt(unsigned char *p, struct rose_facilities_struct *facilities, int len);