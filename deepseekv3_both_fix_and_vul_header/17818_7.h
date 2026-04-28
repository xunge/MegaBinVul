#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define TAG "NTLM"
#define WLOG_INFO 0

typedef struct _NTLM_AV_PAIR NTLM_AV_PAIR;

enum
{
    MsvAvEOL
};

typedef uint16_t UINT16;
typedef uint8_t BYTE;

extern const char* AV_PAIR_STRINGS[];
extern const char* get_av_pair_string(UINT16 id);

/* First version functions */
extern int ntlm_av_pair_check(NTLM_AV_PAIR* pAvPair, size_t cbAvPair);
extern int ntlm_av_pair_get_id_v1(NTLM_AV_PAIR* pAvPair, size_t cbAvPair, UINT16* pPair);
extern int ntlm_av_pair_get_len_v1(NTLM_AV_PAIR* pAvPair, size_t cbAvPair, size_t* pLen);

/* Second version functions */
extern UINT16 ntlm_av_pair_get_id_v2(NTLM_AV_PAIR* pAvPair);
extern UINT16 ntlm_av_pair_get_len_v2(NTLM_AV_PAIR* pAvPair);

extern BYTE* ntlm_av_pair_get_value_pointer(NTLM_AV_PAIR* pAvPair);
extern NTLM_AV_PAIR* ntlm_av_pair_next(NTLM_AV_PAIR* pAvPair, size_t* pcbAvPair);
extern void WLog_INFO(const char* tag, const char* fmt, ...);
extern void winpr_HexDump(const char* tag, int level, const BYTE* data, size_t length);