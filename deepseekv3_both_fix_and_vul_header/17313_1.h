#include <stdlib.h>

#define MAXSTRING 256
#define LOG_ERROR 1

typedef struct {
    int length;
    unsigned short *chars;
} CharsString;

typedef struct {
    char *fileName;
} FileInfo;

typedef struct CharacterClass CharacterClass;
typedef struct TranslationTableCharacterAttributes TranslationTableCharacterAttributes;
typedef struct TranslationTableOffset TranslationTableOffset;
typedef struct TranslationTableRule TranslationTableRule;
typedef struct RuleName RuleName;
typedef struct TranslationTableHeader TranslationTableHeader;

extern int errorCount;
extern char **_lou_resolveTable(const char *includeThis, const char *fileName);
extern void free_tablefiles(char **tableFiles);
extern void _lou_logMessage(int level, const char *format, ...);
extern int compileFile(const char *tableFile, CharacterClass **characterClasses,
    TranslationTableCharacterAttributes *characterClassAttribute, short opcodeLengths[],
    TranslationTableOffset *newRuleOffset, TranslationTableRule **newRule,
    RuleName **ruleNames, TranslationTableHeader **table);