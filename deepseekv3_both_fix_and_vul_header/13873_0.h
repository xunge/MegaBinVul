#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ttfinfo {
    int feat_start;
    int copyright_start;
    char *copyright;
    char *familyname;
    char *fullname;
    char *version;
    char *fontname;
    void *features;
};

struct macsetting {
    char *setname;
    struct macsetting *next;
};

typedef struct MacFeat {
    char *featname;
    struct macsetting *settings;
    struct MacFeat *next;
} MacFeat;

enum {
    ttf_copyright,
    ttf_family,
    ttf_fullname,
    ttf_version,
    ttf_postscriptname
};

static unsigned short getushort(FILE *ttf);
static void readmacfeaturemap(FILE *ttf, struct ttfinfo *info);
static void TTFAddLangStr(FILE *ttf, struct ttfinfo *info, int name, int str_len, int stroff, int platform, int specific, int language);
static char *FindLangEntry(struct ttfinfo *info, int type);
static char *copy(const char *str);
static int strnmatch(const char *str1, const char *str2, int n);
static char *stripspaces(char *str);
static void ValidatePostScriptFontName(struct ttfinfo *info, char *name);
static char *reversemacnames(char *name);