#include <stdint.h>
#include <string.h>

typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} Str;

typedef uint32_t wc_uint32;
typedef unsigned char wc_uchar;
typedef int wc_bool;

#define WC_FALSE 0
#define WC_TRUE 1

typedef struct {
    int ccs;
    wc_uint32 code;
} wc_wchar_t;

typedef struct {
    int g0_ccs;
} wc_status;

struct WcOption {
    int use_jisx0212;
    int use_jisx0213;
    int ucs_conv;
    int no_replace;
} WcOption;

#define WC_CCS_US_ASCII 0
#define WC_CCS_UNKNOWN 1
#define WC_CCS_UNKNOWN_W 2
#define WC_CCS_JIS_X_0212 3
#define WC_CCS_JIS_X_0213_1 4
#define WC_CCS_JIS_X_0213_2 5
#define WC_CCS_JOHAB 6
#define WC_CCS_JOHAB_1 7
#define WC_CCS_JOHAB_2 8
#define WC_CCS_JOHAB_3 9
#define WC_CCS_KS_X_1001 10

#define WC_F_ISO_BASE 0
#define WC_F_KS_X_1001 0

#define WC_CCS_TYPE(x) 0
#define WC_CCS_INDEX(x) 0
#define WC_CCS_IS_WIDE(x) 0

#define WC_CCS_A_CS94 0
#define WC_CCS_A_CS94W 1
#define WC_CCS_A_CS96 2
#define WC_CCS_A_CS96W 3
#define WC_CCS_A_CS942 4
#define WC_CCS_A_UNKNOWN_W 5
#define WC_CCS_A_UNKNOWN 6

extern wc_uchar cs94_gmap[];
extern wc_uchar cs94w_gmap[];
extern wc_uchar cs96_gmap[];
extern wc_uchar cs96w_gmap[];
extern wc_uchar cs942_gmap[];

extern unsigned char WC_REPLACE_W[2];
extern unsigned char WC_REPLACE[1];

void Strcat_char(Str os, char c);
void wc_push_iso2022_esc(Str os, int ccs, wc_uchar g, int flag, wc_status* st);
wc_wchar_t wc_jisx0212_to_jisx0213(wc_wchar_t cc);
wc_wchar_t wc_jisx0213_to_jisx0212(wc_wchar_t cc);
wc_wchar_t wc_johab_to_ksx1001(wc_wchar_t cc);
wc_wchar_t wc_any_to_iso2022(wc_wchar_t cc, wc_status* st);
wc_wchar_t wc_any_to_any_ces(wc_wchar_t cc, wc_status* st);