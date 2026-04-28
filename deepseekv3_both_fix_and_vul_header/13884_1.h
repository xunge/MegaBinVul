#include <stdlib.h>
#include <string.h>

typedef struct jas_taginfo_s {
    int id;
    char *name;
} jas_taginfo_t;

typedef struct jas_taginfo_s *jas_taginfos_t;

typedef struct mif_hdr_s {
    int numcmpts;
} mif_hdr_t;

typedef struct mif_cmpt_s {
    int tlx;
    int tly;
    int sampperx;
    int samppery;
    int width;
    int height;
    int prec;
    int sgnd;
    char *data;
} mif_cmpt_t;

typedef struct jas_tvparser_s jas_tvparser_t;

enum {
    MIF_TLX,
    MIF_TLY,
    MIF_WIDTH,
    MIF_HEIGHT,
    MIF_HSAMP,
    MIF_VSAMP,
    MIF_PREC,
    MIF_SGND,
    MIF_DATA
};

extern jas_taginfos_t mif_tags;
extern mif_cmpt_t *mif_cmpt_create(void);
extern void mif_cmpt_destroy(mif_cmpt_t *cmpt);
extern int mif_hdr_addcmpt(mif_hdr_t *hdr, int cmptno, mif_cmpt_t *cmpt);
extern jas_tvparser_t *jas_tvparser_create(char *s);
extern void jas_tvparser_destroy(jas_tvparser_t *tvp);
extern int jas_tvparser_next(jas_tvparser_t *tvp);
extern char *jas_tvparser_gettag(jas_tvparser_t *tvp);
extern char *jas_tvparser_getval(jas_tvparser_t *tvp);
extern jas_taginfo_t *jas_taginfos_lookup(jas_taginfos_t taginfos, char *name);
extern jas_taginfo_t *jas_taginfo_nonull(jas_taginfo_t *taginfo);
extern char *jas_strdup(const char *s);