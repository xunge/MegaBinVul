#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ScriptParser ScriptParser;
typedef struct Codec Codec;

struct Codec {
    int LastError;
};

struct ScriptParser {
    Codec* codec;
};

void SFS_Expression(ScriptParser *parser);
void SFS_AddString(ScriptParser *parser, const char *str);
void SFS_Identifier(ScriptParser *parser);