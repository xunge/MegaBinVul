#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ttflangname {
    int lang;
    char **names;
    struct ttflangname *next;
};

typedef struct _SplineFont {
    char *familyname;
    char *copyright;
    char *fullname;
    char *version;
    int subfontcnt;
    double cidversion;
    struct ttflangname *names;
} SplineFont;

enum {
    ttf_copyright,
    ttf_family,
    ttf_subfamily,
    ttf_fullname,
    ttf_version,
    ttf_postscriptname
};

char *SFGetModifiers(SplineFont *sf);