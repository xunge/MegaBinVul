#include <stddef.h>

#define FAILURE 0
#define SUCCESS 1

enum entity_charset {
    cs_8859_1,
    cs_8859_5,
    cs_8859_15,
    cs_cp1252,
    cs_macroman,
    cs_cp1251,
    cs_koi8r,
    cs_cp866,
    cs_sjis,
    cs_eucjp,
    cs_big5,
    cs_big5hkscs,
    cs_gb2312
};

typedef struct {
    unsigned code;
    unsigned char mapped;
} uni_to_enc;

extern unsigned char unimap_bsearch(const uni_to_enc *table, unsigned code, size_t table_size);

extern const uni_to_enc unimap_iso885915[256];
extern const uni_to_enc unimap_win1252[256];
extern const uni_to_enc unimap_macroman[256];
extern const uni_to_enc unimap_win1251[256];
extern const uni_to_enc unimap_koi8r[256];
extern const uni_to_enc unimap_cp866[256];