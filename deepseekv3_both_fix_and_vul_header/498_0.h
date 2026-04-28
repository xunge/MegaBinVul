#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CdtmLoader {
public:
    long unpack_pattern(unsigned char *ibuf, long ilen, unsigned char *obuf, long olen);
};