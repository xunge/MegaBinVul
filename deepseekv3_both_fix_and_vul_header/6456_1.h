#include <stdio.h>

typedef struct SWF_TEXTRECORD {
    int TextRecordType;
    int StyleFlagHasFont;
    int StyleFlagHasColor;
    int StyleFlagHasYOffset;
    int StyleFlagHasXOffset;
    int FontID;
    int TextHeight;
    struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
    } TextColor;
    int XOffset;
    int YOffset;
    int GlyphCount;
    struct {
        unsigned char GlyphIndex[1];
    } *GlyphEntries;
} SWF_TEXTRECORD;

struct FONTINFO {
    int fontcodeID;
    char *fontcodeptr;
    int fontcodearrsize;
    struct FONTINFO *next;
};

extern struct FONTINFO *fip;
extern struct FONTINFO *fip_current;
extern char *methodcall(char *tname, char *method);
#define VAR ""