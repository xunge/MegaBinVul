#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

typedef int32_t jpc_fix_t;

#define JAS_CLRSPC_FAM_RGB 1

struct jas_image_s {
    unsigned numcmpts;
    uint_fast32_t (*rawsize)(struct jas_image_s *image);
    uint_fast32_t (*cmptbrx)(struct jas_image_s *image, unsigned cmptno);
    uint_fast32_t (*cmpthstep)(struct jas_image_s *image, unsigned cmptno);
    uint_fast32_t (*brx)(struct jas_image_s *image);
    uint_fast32_t (*cmptbry)(struct jas_image_s *image, unsigned cmptno);
    uint_fast32_t (*cmptvstep)(struct jas_image_s *image, unsigned cmptno);
    uint_fast32_t (*bry)(struct jas_image_s *image);
    uint_fast16_t (*cmptprec)(struct jas_image_s *image, unsigned cmptno);
    bool (*cmptsgnd)(struct jas_image_s *image, unsigned cmptno);
    unsigned (*clrspc_fam)(unsigned clrspc);
    unsigned (*clrspc)(struct jas_image_s *image);
    uint_fast32_t (*cmptwidth)(struct jas_image_s *image, unsigned cmptno);
    uint_fast32_t (*cmptheight)(struct jas_image_s *image, unsigned cmptno);
    unsigned (*get_width)(struct jas_image_s *image);
    unsigned (*get_height)(struct jas_image_s *image);
};
typedef struct jas_image_s jas_image_t;

struct jas_tvparser_s;
typedef struct jas_tvparser_s jas_tvparser_t;

#define JPC_COD_LRCPPRG 0
#define JPC_MAXRLVLS 33
#define JPC_COD_SOP (1 << 0)
#define JPC_COD_EPH (1 << 1)
#define JPC_COX_LAZY (1 << 0)
#define JPC_COX_TERMALL (1 << 1)
#define JPC_COX_SEGSYM (1 << 2)
#define JPC_COX_VSC (1 << 3)
#define JPC_COX_RESET (1 << 4)
#define JPC_COX_PTERM (1 << 5)
#define JPC_COX_PRT (1 << 6)
#define JPC_MCT_RCT 1
#define JPC_MCT_ICT 2
#define JPC_MCT_NONE 0
#define JPC_COX_RFT 0
#define JPC_COX_INS 1

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

typedef struct {
    int id;
    const char *name;
} jas_taginfo_t;

typedef struct {
    uint_fast16_t sampgrdstepx;
    uint_fast16_t sampgrdstepy;
    uint_fast16_t sampgrdsubstepx;
    uint_fast16_t sampgrdsubstepy;
    uint_fast16_t prec;
    bool sgnd;
    uint_fast8_t numstepsizes;
    uint_fast16_t stepsizes[3];
} jpc_enc_ccp_t;

typedef struct {
    uint_fast8_t csty;
    uint_fast8_t maxrlvls;
    uint_fast8_t cblkwidthexpn;
    uint_fast8_t cblkheightexpn;
    uint_fast8_t cblksty;
    uint_fast8_t numgbits;
    uint_fast8_t qmfbid;
    uint_fast8_t prcwidthexpns[JPC_MAXRLVLS];
    uint_fast8_t prcheightexpns[JPC_MAXRLVLS];
} jpc_enc_tccp_t;

typedef struct {
    uint_fast16_t csty;
    bool intmode;
    uint_fast8_t prg;
    uint_fast16_t numlyrs;
    jpc_fix_t *ilyrrates;
    uint_fast8_t mctid;
} jpc_enc_tcp_t;

typedef struct {
    uint_fast32_t imgareatlx;
    uint_fast32_t imgareatly;
    uint_fast32_t refgrdwidth;
    uint_fast32_t refgrdheight;
    uint_fast32_t tilegrdoffx;
    uint_fast32_t tilegrdoffy;
    uint_fast32_t tilewidth;
    uint_fast32_t tileheight;
    uint_fast32_t rawsize;
    uint_fast32_t totalsize;
    uint_fast16_t numcmpts;
    uint_fast16_t numhtiles;
    uint_fast16_t numvtiles;
    uint_fast32_t numtiles;
    int debug;
    jpc_enc_tcp_t tcp;
    jpc_enc_tccp_t tccp;
    jpc_enc_ccp_t *ccps;
} jpc_enc_cp_t;

extern jas_taginfo_t encopts[];
extern jas_taginfo_t modetab[];
extern jas_taginfo_t prgordtab[];

#define JAS_CAST(type, expr) ((type)(expr))
#define JPC_POW2(n) (1 << (n))
#define JPC_CEILDIV(a, b) (((a) + (b) - 1) / (b))

static int jpc_floorlog2(int n) { return (int)log2(n); }
static double jpc_fixtodbl(jpc_fix_t fix) { return (double)fix / (1 << 16); }
static jpc_fix_t jpc_dbltofix(double dbl) { return (jpc_fix_t)(dbl * (1 << 16)); }
static int ratestrtosize(const char *s, uint_fast32_t rawsize, uint_fast32_t *size) { return 0; }
static int jpc_atoaf(const char *s, int *numvalues, double **values) { return 0; }
static void jpc_enc_cp_destroy(jpc_enc_cp_t *cp) { free(cp); }
static void *jas_malloc(size_t size) { return malloc(size); }
static void *jas_alloc2(size_t num_elements, size_t element_size) { return calloc(num_elements, element_size); }
static void jas_free(void *ptr) { free(ptr); }
static void jas_eprintf(const char *format, ...) { va_list args; va_start(args, format); vfprintf(stderr, format, args); va_end(args); }
static unsigned jas_image_numcmpts(jas_image_t *image) { return image->numcmpts; }
static uint_fast32_t jas_image_cmptbrx(jas_image_t *image, unsigned cmptno) { return image->cmptbrx(image, cmptno); }
static uint_fast32_t jas_image_cmpthstep(jas_image_t *image, unsigned cmptno) { return image->cmpthstep(image, cmptno); }
static uint_fast32_t jas_image_brx(jas_image_t *image) { return image->brx(image); }
static uint_fast32_t jas_image_cmptbry(jas_image_t *image, unsigned cmptno) { return image->cmptbry(image, cmptno); }
static uint_fast32_t jas_image_cmptvstep(jas_image_t *image, unsigned cmptno) { return image->cmptvstep(image, cmptno); }
static uint_fast32_t jas_image_bry(jas_image_t *image) { return image->bry(image); }
static uint_fast16_t jas_image_cmptprec(jas_image_t *image, unsigned cmptno) { return image->cmptprec(image, cmptno); }
static bool jas_image_cmptsgnd(jas_image_t *image, unsigned cmptno) { return image->cmptsgnd(image, cmptno); }
static unsigned jas_clrspc_fam(unsigned clrspc) { return 0; }
static jas_tvparser_t *jas_tvparser_create(const char *s) { return NULL; }
static int jas_tvparser_next(jas_tvparser_t *tvp) { return 0; }
static const char *jas_tvparser_gettag(jas_tvparser_t *tvp) { return NULL; }
static const char *jas_tvparser_getval(jas_tvparser_t *tvp) { return NULL; }
static void jas_tvparser_destroy(jas_tvparser_t *tvp) {}
static jas_taginfo_t *jas_taginfos_lookup(jas_taginfo_t *taginfos, const char *name) { return NULL; }
static jas_taginfo_t *jas_taginfo_nonull(jas_taginfo_t *taginfo) { return taginfo; }
static uint_fast32_t jas_image_rawsize(jas_image_t *image) { return image->rawsize(image); }
static unsigned jas_image_width(jas_image_t *image) { return image->get_width(image); }
static unsigned jas_image_height(jas_image_t *image) { return image->get_height(image); }
static uint_fast32_t jas_image_cmptwidth(jas_image_t *image, unsigned cmptno) { return image->cmptwidth(image, cmptno); }
static uint_fast32_t jas_image_cmptheight(jas_image_t *image, unsigned cmptno) { return image->cmptheight(image, cmptno); }
static unsigned jas_image_clrspc(jas_image_t *image) { return image->clrspc(image); }