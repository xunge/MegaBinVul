#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint16_t UINT16;
typedef uint16_t NTLM_AV_ID;

typedef enum {
    MsvAvEOL
} NTLM_AV_ID_VALUES;

typedef struct NTLM_AV_PAIR {
    UINT16 AvId;
    UINT16 AvLen;
} NTLM_AV_PAIR;

extern int ntlm_av_pair_check(NTLM_AV_PAIR* pAvPair, size_t cbAvPair);
extern UINT16 ntlm_av_pair_get_id_3args(NTLM_AV_PAIR* pAvPair, size_t cbAvPair, UINT16* id);
extern UINT16 ntlm_av_pair_get_id_1arg(NTLM_AV_PAIR* pAvPair);
extern NTLM_AV_PAIR* ntlm_av_pair_next(NTLM_AV_PAIR* pAvPair, size_t* pcbAvPair);

static inline UINT16 ntlm_av_pair_get_id(NTLM_AV_PAIR* pAvPair, ...)
{
    va_list args;
    va_start(args, pAvPair);
    
    if (va_arg(args, int)) {
        size_t cbAvPair = va_arg(args, size_t);
        UINT16* id = va_arg(args, UINT16*);
        va_end(args);
        return ntlm_av_pair_get_id_3args(pAvPair, cbAvPair, id);
    }
    
    va_end(args);
    return ntlm_av_pair_get_id_1arg(pAvPair);
}