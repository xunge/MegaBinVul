#include <stddef.h>

typedef int BOOL;
#define FALSE 0

typedef struct _NTLM_AV_PAIR {
    unsigned short AvId;
    unsigned short AvLen;
} NTLM_AV_PAIR;

static size_t ntlm_av_pair_get_next_offset(NTLM_AV_PAIR* pAvPair);