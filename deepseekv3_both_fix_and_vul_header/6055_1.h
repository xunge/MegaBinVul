#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef int32_t jpc_fix_t;

typedef struct jpc_enc_ccp_s {
    uint_fast32_t sampgrdstepx;
    uint_fast32_t sampgrdstepy;
    uint_fast32_t sampgrdsubstepx;
    uint_fast32_t sampgrdsubstepy;
    uint_fast16_t prec;
    bool sgnd;
    uint_fast16_t numstepsizes;
    uint_fast32_t stepsizes[3*33 + 1];
} jpc_enc_ccp_t;

typedef struct jpc_enc_tccp_s {
    uint_fast8_t csty;
    uint_fast8_t maxrlvls;
    uint_fast8_t cblkwidthexpn;
    uint_fast8_t cblkheightexpn;
    uint_fast8_t cblksty;
    uint_fast8_t numgbits;
    uint_fast8_t qmfbid;
    uint_fast8_t prcwidthexpns[33];
    uint_fast8_t prcheightexpns[33];
} jpc_enc_tccp_t;

typedef struct jpc_enc_tcp_s {
    uint_fast8_t csty;
    bool intmode;
    uint_fast8_t prg;
    uint_fast16_t numlyrs;
    jpc_fix_t *ilyrrates;
    uint_fast8_t mctid;
} jpc_enc_tcp_t;

typedef struct jpc_enc_cp_s {
    uint_fast32_t imgareatlx;
    uint_fast32_t imgareatly;
    uint_fast32_t refgrdwidth;
    uint_fast32_t refgrdheight;
    uint_fast32_t tilegrdoffx;
    uint_fast32_t tilegrdoffy;
    uint_fast32_t tilewidth;
    uint_fast32_t tileheight;
    uint_fast32_t numcmpts;
    uint_fast32_t rawsize;
    uint_fast32_t totalsize;
    uint_fast32_t numhtiles;
    uint_fast32_t numvtiles;
    uint_fast32_t numtiles;
    int debug;
    jpc_enc_ccp_t *ccps;
    jpc_enc_tcp_t tcp;
    jpc_enc_tccp_t tccp;
} jpc_enc_cp_t;

typedef struct jas_image_s jas_image_t;
typedef struct jas_tvparser_s jas_tvparser_t;
typedef struct jas_taginfo_s {
    int id;
    const char *name;
} jas_taginfo_t;

#define JPC_COD_LRCPPRG 0
#define JPC_COD_SOP 1
#define JPC_COD_EPH 2
#define JPC_COX_LAZY 1
#define JPC_COX_TERMALL 2
#define JPC_COX_SEGSYM 4
#define JPC_COX_VSC 8
#define JPC_COX_RESET 16
#define JPC_COX_PTERM 32
#define JPC_COX_PRT 64
#define JPC_COX_RFT 0
#define JPC_COX_INS 1
#define JPC_MCT_NONE 0
#define JPC_MCT_RCT 1
#define JPC_MCT_ICT 2
#define JAS_CLRSPC_FAM_RGB 1

#define JAS_CAST(t, e) ((t)(e))
#define JPC_POW2(x) (1 << (x))
#define JPC_CEILDIV(x, y) (((x) + (y) - 1) / (y))

enum {
    OPT_DEBUG,
    OPT_IMGAREAOFFX,
    OPT_IMGAREAOFFY,
    OPT_TILEGRDOFFX,
    OPT_TILEGRDOFFY,
    OPT_TILEWIDTH,
    OPT_TILEHEIGHT,
    OPT_PRCWIDTH,
    OPT_PRCHEIGHT,
    OPT_CBLKWIDTH,
    OPT_CBLKHEIGHT,
    OPT_MODE,
    OPT_PRG,
    OPT_NOMCT,
    OPT_MAXRLVLS,
    OPT_SOP,
    OPT_EPH,
    OPT_LAZY,
    OPT_TERMALL,
    OPT_SEGSYM,
    OPT_VCAUSAL,
    OPT_RESET,
    OPT_PTERM,
    OPT_NUMGBITS,
    OPT_RATE,
    OPT_ILYRRATES,
    OPT_JP2OVERHEAD
};

enum {
    MODE_INT,
    MODE_REAL
};

static jas_taginfo_t encopts[] = {
    {OPT_DEBUG, "debug"},
    {OPT_IMGAREAOFFX, "imgareatlx"},
    {OPT_IMGAREAOFFY, "imgareatly"},
    {OPT_TILEGRDOFFX, "tilegrdoffx"},
    {OPT_TILEGRDOFFY, "tilegrdoffy"},
    {OPT_TILEWIDTH, "tilewidth"},
    {OPT_TILEHEIGHT, "tileheight"},
    {OPT_PRCWIDTH, "prcwidth"},
    {OPT_PRCHEIGHT, "prcheight"},
    {OPT_CBLKWIDTH, "cblkwidth"},
    {OPT_CBLKHEIGHT, "cblkheight"},
    {OPT_MODE, "mode"},
    {OPT_PRG, "prg"},
    {OPT_NOMCT, "nomct"},
    {OPT_MAXRLVLS, "maxrlvls"},
    {OPT_SOP, "sop"},
    {OPT_EPH, "eph"},
    {OPT_LAZY, "lazy"},
    {OPT_TERMALL, "termall"},
    {OPT_SEGSYM, "segsym"},
    {OPT_VCAUSAL, "vcausal"},
    {OPT_RESET, "reset"},
    {OPT_PTERM, "pterm"},
    {OPT_NUMGBITS, "numgbits"},
    {OPT_RATE, "rate"},
    {OPT_ILYRRATES, "ilyrrates"},
    {OPT_JP2OVERHEAD, "jp2overhead"},
    {0, 0}
};

static jas_taginfo_t modetab[] = {
    {MODE_INT, "int"},
    {MODE_REAL, "real"},
    {0, 0}
};

static jas_taginfo_t prgordtab[] = {
    {JPC_COD_LRCPPRG, "lrcp"},
    {0, 0}
};

static void *jas_malloc(size_t size) { return malloc(size); }
static void *jas_alloc2(size_t num, size_t size) { return calloc(num, size); }
static void jas_free(void *ptr) { free(ptr); }
static int jas_tvparser_next(jas_tvparser_t *tvp) { return 0; }
static jas_tvparser_t *jas_tvparser_create(const char *s) { return NULL; }
static void jas_tvparser_destroy(jas_tvparser_t *tvp) {}
static const char *jas_tvparser_gettag(jas_tvparser_t *tvp) { return NULL; }
static const char *jas_tvparser_getval(jas_tvparser_t *tvp) { return NULL; }
static jas_taginfo_t *jas_taginfos_lookup(jas_taginfo_t *taginfos, const char *name) { return NULL; }
static jas_taginfo_t *jas_taginfo_nonull(jas_taginfo_t *taginfo) { return taginfo; }
static void jas_eprintf(const char *fmt, ...) {}
static int jas_image_numcmpts(jas_image_t *image) { return 0; }
static uint_fast32_t jas_image_width(jas_image_t *image) { return 0; }
static uint_fast32_t jas_image_height(jas_image_t *image) { return 0; }
static uint_fast32_t jas_image_rawsize(jas_image_t *image) { return 0; }
static uint_fast32_t jas_image_cmptwidth(jas_image_t *image, int cmptno) { return 0; }
static uint_fast32_t jas_image_cmptheight(jas_image_t *image, int cmptno) { return 0; }
static uint_fast32_t jas_image_cmptprec(jas_image_t *image, int cmptno) { return 0; }
static bool jas_image_cmptsgnd(jas_image_t *image, int cmptno) { return false; }
static uint_fast32_t jas_image_cmpthstep(jas_image_t *image, int cmptno) { return 0; }
static uint_fast32_t jas_image_cmptvstep(jas_image_t *image, int cmptno) { return 0; }
static uint_fast32_t jas_image_brx(jas_image_t *image) { return 0; }
static uint_fast32_t jas_image_bry(jas_image_t *image) { return 0; }
static uint_fast32_t jas_image_cmptbrx(jas_image_t *image, int cmptno) { return 0; }
static uint_fast32_t jas_image_cmptbry(jas_image_t *image, int cmptno) { return 0; }
static int jas_clrspc_fam(int clrspc) { return 0; }
static void jpc_enc_cp_destroy(jpc_enc_cp_t *cp) {}
static int jpc_floorlog2(int n) { return (int)log2(n); }
static int jpc_atoaf(const char *s, int *numvalues, double **values) { return 0; }
static jpc_fix_t jpc_dbltofix(double x) { return (jpc_fix_t)(x * (1 << 8)); }
static double jpc_fixtodbl(jpc_fix_t x) { return (double)x / (1 << 8); }
static int ratestrtosize(const char *s, uint_fast32_t rawsize, uint_fast32_t *size) { return 0; }