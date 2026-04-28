#include <time.h>
#include <string.h>
#include <stdio.h>

struct ttflangname {
    char *names[20];
};

enum {
    ttf_copyright,
    ttf_family,
    ttf_subfamily,
    ttf_uniqueid,
    ttf_fullname,
    ttf_version,
    ttf_postscriptname
};

struct splinefont {
    char *copyright;
    char *familyname;
    char *fullname;
    char *fontname;
    char *version;
    int subfontcnt;
    float cidversion;
};

typedef struct splinefont SplineFont;

extern char *BDFFoundry;
extern char *TTFFoundry;
extern char *utf8_verify_copy(const char *);
extern char *copy(const char *);
extern char *SFGetModifiers(SplineFont *);