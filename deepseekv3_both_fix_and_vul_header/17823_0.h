#include <stddef.h>

typedef unsigned short UINT16;
typedef int BOOL;
#define FALSE 0
#define TRUE 1
#define INLINE inline

typedef struct _NTLM_AV_PAIR {
    UINT16 AvId;
    UINT16 AvLen;
} NTLM_AV_PAIR;

static void Data_Read_UINT16(const UINT16* source, UINT16* dest) {
    *dest = *source;
}