#include <stddef.h>

typedef struct HTStructured HTStructured;
typedef struct HTChunk HTChunk;
typedef struct HText HText;

#define LYMapsOnly 0
#define HTML_OBJECT 1
#define HTML_COMMENT 2
#define HTML_TITLE 3
#define HTML_STYLE 4
#define HTML_SCRIPT 5
#define HTML_PRE 6
#define HTML_LISTING 7
#define HTML_XMP 8
#define HTML_PLAINTEXT 9
#define HTML_TEXTAREA 10
#define HTML_SELECT 11
#define HTML_OPTION 12
#define HTML_MATH 13

#define USE_PRETTYSRC 0
#define YES 1
#define NO 0
#define FIX_JAPANESE_SPACES 0
static int psrc_convert_string = 0;
static int psrc_view = 0;
#define tfp NULL
#define TRUE 1
#define FALSE 0

struct HTChunk {
    char *data;
    size_t size;
};

struct HTStructured {
    struct {
        int tag_number;
        struct {
            int freeFormat;
        } *style;
    } sp[1];
    HTChunk title;
    HTChunk style_block;
    HTChunk script;
    HText *text;
    HTChunk object;
    HTChunk textarea;
    HTChunk option;
    HTChunk math;
    int style_change;
    int in_word;
};

void HText_appendText(HText *text, const char *s);
void HText_appendCharacter(HText *text, char c);
char HText_getLastChar(HText *text);
void HText_setLastChar(HText *text, char c);
void HTML_put_character(HTStructured *me, char c);
void HTChunkPuts(HTChunk *target, const char *s);
void StrAllocCopy(char **dest, const char *src);
void FREE(void *ptr);
#define TRANSLATE_AND_UNESCAPE_ENTITIES(str, a, b)
#define UPDATE_STYLE
#define CTRACE(args)