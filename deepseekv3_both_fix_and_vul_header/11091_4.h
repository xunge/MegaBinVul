#include <stdlib.h>
#include <stdbool.h>

typedef struct OTLookup OTLookup;
typedef struct SplineFont1 SplineFont1;
typedef struct SplineChar SplineChar;
typedef struct FeatureScriptLangList FeatureScriptLangList;

struct OTLookup {
    FeatureScriptLangList *features;
    int lookup_index;
    OTLookup *next;
};

struct FeatureScriptLangList {
    void *scripts;
};

struct SplineFont1 {
    struct {
        int uni_interp;
        struct {
            void *enc;
        } *map;
        struct {
            int os2_winascent;
            bool winascent_add;
            bool windescent_add;
            int os2_windescent;
        } pfminfo;
        int ascent;
        int subfontcnt;
        SplineFont1 **subfonts;
        int glyphcnt;
        SplineChar **glyphs;
        void *vkerns;
        void *kerns;
        void *possub;
        void *sm;
        void *anchor;
        OTLookup *gpos_lookups;
        OTLookup *gsub_lookups;
    } sf;
};

struct SplineChar {
    void *possub;
    void *vkerns;
    void *kerns;
};

typedef struct PST1 {
    struct {
        int type;
        void *subtable;
        void *next;
    } pst;
    int tag;
    int script_lang_index;
    int flags;
} PST1;

typedef struct KernPair1 {
    struct {
        void *subtable;
        void *next;
    } kp;
    int sli;
    int flags;
} KernPair1;

typedef struct KernClass1 {
    struct {
        void *subtable;
        void *next;
    } kc;
    int sli;
    int flags;
} KernClass1;

typedef struct FPST1 {
    struct {
        int type;
        void *subtable;
        void *next;
    } fpst;
    int tag;
    int script_lang_index;
    int flags;
} FPST1;

typedef struct ASM1 {
    struct {
        int type;
        void *subtable;
        void *next;
    } sm;
} ASM1;

typedef struct AnchorClass1 {
    struct {
        int type;
        void *subtable;
        void *next;
    } ac;
    int feature_tag;
    int script_lang_index;
    int flags;
    bool has_ligatures;
    bool has_bases;
    void *merge_with;
} AnchorClass1;

typedef struct lookup_subtable {
    bool per_glyph_pst_or_kern;
    void *kc;
    void *fpst;
    void *sm;
} lookup_subtable;

enum {
    ui_unset,
    ui_none,
    pst_lcaret,
    pst_pair,
    asm_context,
    act_mklg
};

#define CHR(a,b,c,d) ((a)<<24|(b)<<16|(c)<<8|(d))

OTLookup *CreateLookup(SplineFont1 *sf, int tag, int script_lang_index, int flags, int type);
lookup_subtable *CreateSubtable(OTLookup *otl, SplineFont1 *sf);
void SFDCleanupAnchorClasses(struct SplineFont1 *sf);
int interp_from_encoding(void *enc, int ui_none);
OTLookup *CreateMacLookup(SplineFont1 *sf, ASM1 *sm);
void FPSTReplaceTagsWithLookups(void *fpst, SplineFont1 *sf);
void ASMReplaceTagsWithLookups(void *sm, SplineFont1 *sf);
void ACHasBaseLig(SplineFont1 *sf, AnchorClass1 *ac);
void ACDisassociateLigatures(SplineFont1 *sf, AnchorClass1 *ac);
OTLookup *CreateACLookup(SplineFont1 *sf, AnchorClass1 *ac);
int GSubOrder(SplineFont1 *sf, FeatureScriptLangList *features);
int order_lookups(const void *a, const void *b);
void NameOTLookup(OTLookup *otl, struct SplineFont1 *sf);
void chunkfree(void *ptr, size_t size);