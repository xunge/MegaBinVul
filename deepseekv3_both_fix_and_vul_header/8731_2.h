#include <stdint.h>
#include <stddef.h>

typedef uint32_t wc_uint32;
typedef uint16_t wc_uint16;

typedef struct {
    wc_uint16 ccs;
    wc_uint32 code;
} wc_wchar_t;

typedef struct {
    wc_uint16 code1;
    wc_uint32 code2;
} wc_map;

extern wc_map *wc_map_search(wc_uint16 code, wc_map *map, size_t size);
extern wc_wchar_t wc_tcvn57123_to_tcvn5712(wc_wchar_t cc);
extern wc_wchar_t wc_johab_to_cs128w(wc_wchar_t cc);
extern wc_wchar_t wc_sjis_ext_to_cs94w(wc_wchar_t cc);
extern wc_wchar_t wc_cs128w_to_hkscs(wc_wchar_t cc);
extern wc_wchar_t wc_cs128w_to_gbk(wc_wchar_t cc);
extern wc_wchar_t wc_cs128w_to_uhc(wc_wchar_t cc);
extern wc_uint32 wc_gb18030_to_ucs(wc_wchar_t cc);
extern wc_uint32 wc_ucs_tag_to_ucs(wc_uint32 code);
extern wc_uint32 wc_hkscs_to_N(wc_uint32 code);
extern wc_uint32 wc_gbk_to_N(wc_uint32 code);
extern wc_uint32 wc_uhc_to_N(wc_uint32 code);
extern wc_uint32 wc_sjis_ext1_to_N(wc_uint32 code);
extern wc_uint32 wc_sjis_ext2_to_N(wc_uint32 code);

extern wc_uint16 *cs94_ucs_map[];
extern wc_uint16 *cs94w_ucs_map[];
extern wc_uint16 *cs96_ucs_map[];
extern wc_uint16 *cs96w_ucs_map[];
extern wc_uint16 *cs942_ucs_map[];
extern wc_uint16 *pcs_ucs_map[];
extern wc_uint16 *pcsw_ucs_map[];

extern size_t cs94w_ucs_map_size[];
extern size_t cs96w_ucs_map_size[];
extern size_t pcs_ucs_map_size[];
extern size_t pcsw_ucs_map_size[];

extern wc_map jisx02131_ucs_p2_map[];
extern wc_map jisx02132_ucs_p2_map[];
extern wc_map cp12582_ucs_map[];
extern wc_map hkscs_ucs_p2_map[];
extern wc_map johab2_ucs_map[];

extern size_t N_jisx02131_ucs_p2_map;
extern size_t N_jisx02132_ucs_p2_map;
extern size_t N_cp12582_ucs_map;
extern size_t N_hkscs_ucs_p2_map;
extern size_t N_johab2_ucs_map;

extern struct {
    int use_gb12345_map;
} WcOption;

#define WC_CCS_INDEX(ccs) ((ccs) & 0x1f)
#define WC_CCS_TYPE(ccs) ((ccs) >> 5)
#define WC_CCS_SET(ccs) ((ccs) & 0x1f00)

#define WC_F_ISO_BASE 0
#define WC_F_CS94_END 0
#define WC_F_CS94W_END 0
#define WC_F_CS96_END 0
#define WC_F_CS96W_END 0
#define WC_F_CS942_END 0
#define WC_F_PCS_BASE 0
#define WC_F_PCS_END 0
#define WC_F_PCSW_END 0

#define WC_CCS_US_ASCII 1
#define WC_CCS_GB_2312 2
#define WC_CCS_GB_12345 3
#define WC_CCS_JIS_X_0213_1 4
#define WC_CCS_JIS_X_0213_2 5
#define WC_CCS_CP1258_2 6
#define WC_CCS_TCVN_5712_3 7
#define WC_CCS_GBK_80 8
#define WC_CCS_BIG5 9
#define WC_CCS_BIG5_2 10
#define WC_CCS_HKSCS_1 11
#define WC_CCS_HKSCS_2 12
#define WC_CCS_HKSCS 13
#define WC_CCS_JOHAB 14
#define WC_CCS_JOHAB_1 15
#define WC_CCS_JOHAB_2 16
#define WC_CCS_JOHAB_3 17
#define WC_CCS_SJIS_EXT 18
#define WC_CCS_SJIS_EXT_1 19
#define WC_CCS_SJIS_EXT_2 20
#define WC_CCS_GBK_1 21
#define WC_CCS_GBK_2 22
#define WC_CCS_GBK 23
#define WC_CCS_GBK_EXT 24
#define WC_CCS_GBK_EXT_1 25
#define WC_CCS_GBK_EXT_2 26
#define WC_CCS_UHC_1 27
#define WC_CCS_UHC_2 28
#define WC_CCS_UHC 29
#define WC_CCS_UCS2 30
#define WC_CCS_UCS4 31
#define WC_CCS_UCS_TAG 32
#define WC_CCS_GB18030 33
#define WC_CCS_C1 34

#define WC_C_UCS4_ERROR 0
#define WC_C_UCS4_PLANE2 0x10000
#define WC_C_BIG5_2_BASE 0
#define WC_C_UCS2_HANGUL 0
#define WC_C_UHC_END 0
#define WC_C_SJIS_ERROR 0
#define WC_C_UCS2_EURO 0x20AC

#define WC_CS94W_N(code) ((code) & 0x7f7f)
#define WC_CS96W_N(code) ((code) & 0x7f7f)
#define WC_CS94x128_N(code) ((code) & 0x7f7f)
#define WC_CS128W_N(code) ((code) & 0x7f7f)
#define WC_N_JOHAB2(code) ((code) & 0x7f7f)
#define WC_BIG5_N(code) ((code) & 0x7f7f)

#define WC_CCS_A_CS94 0
#define WC_CCS_A_CS94W 1
#define WC_CCS_A_CS96 2
#define WC_CCS_A_CS96W 3
#define WC_CCS_A_CS942 4
#define WC_CCS_A_PCS 5
#define WC_CCS_A_PCSW 6
#define WC_CCS_A_WCS16 7
#define WC_CCS_A_WCS32 8
#define WC_CCS_A_UNKNOWN 9