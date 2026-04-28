#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint;
typedef char* tmbstr;
typedef const char* ctmbstr;
typedef char tmbchar;

typedef enum {
    no,
    yes
} Bool;

#define EndOfStream (-1)
#define TidyLiteralAttribs 0
#define UNEXPECTED_END_OF_FILE_ATTR 0
#define UNEXPECTED_QUOTEMARK 0
#define UNEXPECTED_GT 0
#define NEWLINE_IN_URI 0
#define WHITE_IN_URI 0
#define SUSPECTED_MISSING_QUOTE 0
#define IgnoreWhitespace 0

typedef struct TidyDocImpl {
    struct Lexer* lexer;
    void* docIn;
    void* allocator;
} TidyDocImpl;

typedef struct Lexer {
    int lexsize;
    char* lexbuf;
    void* token;
} Lexer;

/* Remove TY_ prefix from all function declarations */
int ReadChar(void* docIn);
void UngetChar(int c, void* docIn);
Bool IsWhite(uint c);
void AddCharToLexer(struct Lexer* lexer, uint c);
int ParseServerInstruction(struct TidyDocImpl* doc);
void ReportAttrError(struct TidyDocImpl* doc, void* token, void* null, int error);
tmbstr tmbstrndup(void* allocator, const char* str, size_t len);
Bool IsUrl(struct TidyDocImpl* doc, ctmbstr name);
void ParseEntity(struct TidyDocImpl* doc, int mode);
void ChangeChar(struct Lexer* lexer, char c);
Bool IsUpper(uint c);
uint ToLower(uint c);
Bool IsScript(struct TidyDocImpl* doc, ctmbstr name);
int tmbstrncmp(const char* s1, const char* s2, size_t n);
int tmbstrcasecmp(ctmbstr s1, ctmbstr s2);
void ReportFatal(struct TidyDocImpl* doc, void* null1, void* null2, int error);
Bool cfgBool(struct TidyDocImpl* doc, int option);

/* Define TY_ macros to map to unprefixed functions */
#define TY_(x) x