#include <stdio.h>

#define VAR ""

typedef struct SWF_TEXTRECORD {
    int TextRecordType;
    int StyleFlagHasFont;
    int FontID;
    int TextHeight;
    int StyleFlagHasColor;
    struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
    } TextColor;
    int StyleFlagHasYOffset;
    int StyleFlagHasXOffset;
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
extern void SWF_warn(const char *msg);