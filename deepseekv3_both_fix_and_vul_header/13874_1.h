#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef double real;

struct topdicts {
    char *fontname;
    real underlinepos;
    real underlinewidth;
    int charstringtype;
    real fontmatrix[6];
    int fontmatrix_set;
    int version;
    int notice;
    int copyright;
    int fullname;
    int familyname;
    int weight;
    int isfixedpitch;
    real italicangle;
    int painttype;
    int uniqueid;
    real fontbb[4];
    real strokewidth;
    real xuid[20];
    int charsetoff;
    int encodingoff;
    int charstringsoff;
    int private_size;
    int private_offset;
    int synthetic_base;
    int postscript_code;
    int basefontname;
    real basefontblend[16];
    int nMasters;
    int nAxes;
    real weightvector[16];
    int lenBuildCharArray;
    int NormalizeDesignVector;
    int ConvertDesignVector;
    int blendaxistypes[16];
    int ros_registry;
    int ros_ordering;
    int ros_supplement;
    int cidfontversion;
    int cidfontrevision;
    int cidfonttype;
    int cidcount;
    int uidbase;
    int fdarrayoff;
    int fdselectoff;
    int sid_fontname;
};

struct ttfinfo {
    bool bad_cff;
};

extern void ValidatePostScriptFontName(struct ttfinfo *info, char *fontname);
extern int readcffthing(FILE *ttf, int *ival, real *stack, int *oval, struct ttfinfo *info);
extern void skipcfft2thing(FILE *ttf);
extern void LogError(const char *format, ...);