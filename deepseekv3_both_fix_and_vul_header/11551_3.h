#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

typedef unsigned short Unicode;
typedef int GBool;
#define gFalse 0
#define gTrue 1

typedef void* xmlNodePtr;
typedef unsigned char xmlChar;

class IWord;
class TextFontStyleInfo;
class UnicodeMap;
class GString;

class TextPage {
public:
    void addAttributsNode(xmlNodePtr node, IWord *word, double &xMaxi,
                         double &yMaxi, double &yMinRot, double &yMaxRot, double &xMinRot,
                         double &xMaxRot, TextFontStyleInfo *fontStyleInfo, UnicodeMap *uMap, GBool fullFontName);
};

class GString {
public:
    GString(const char* str = "");
    const char* getCString();
    GString* lowerCase();
};

class UnicodeMap {
};

class TextFontStyleInfo {
public:
    void setFontName(GString* name);
    void setFontType(GBool isSerif);
    void setFontWidth(GBool isFixedWidth);
    void setIsBold(GBool isBold);
    void setIsItalic(GBool isItalic);
    void setFontSize(double size);
    void setFontColor(GString* color);
    void setId(int id);
    int getId();
    GBool cmp(TextFontStyleInfo* other);
};

class IWord {
public:
    int getIdx();
    char* getFontName();
    char* normalizeFontName(char* name);
    GBool isBold();
    GBool isItalic();
    GString* colortoString();
    int size;
    int len;
    class CharCollection* chars;
    double xMin, yMin, xMax, yMax, base, fontSize;
    class Font* font;
};

class CharCollection {
public:
    void* get(int index);
};

class Font {
public:
    GBool isSerif();
    GBool isFixedWidth();
};

class TextChar {
public:
    Unicode c;
};

extern int num;
extern int numToken;
extern const char* ATTR_SID;
extern const char* ATTR_ID;
extern const char* ATTR_HIGHLIGHT;
extern const char* ATTR_TOKEN_CONTENT;
extern const char* ATTR_NUMFORMAT;
extern const char* ATTR_X;
extern const char* ATTR_Y;
extern const char* ATTR_BASE;
extern const char* ATTR_WIDTH;
extern const char* ATTR_HEIGHT;
extern const char* ATTR_STYLEREFS;
extern std::vector<TextFontStyleInfo*> fontStyles;

void* grealloc(void* ptr, size_t size);
void gfree(void* ptr);
GString* buildSID(int num, int idx, GString* id);
GString* buildIdToken(int num, int token, GString* id);
void testLinkedText(xmlNodePtr node, double xMin, double yMin, double xMax, double yMax);
GBool testAnnotatedText(double xMin, double yMin, double xMax, double yMax);
void dumpFragment(Unicode* text, int len, UnicodeMap* uMap, GString* stringTemp);
xmlNodePtr xmlNewProp(xmlNodePtr node, const xmlChar* name, const xmlChar* value);
int xmlStrlen(const xmlChar* str);