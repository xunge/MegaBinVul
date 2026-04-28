#include <stdlib.h>

typedef struct ScriptParser ScriptParser;
typedef struct {
    int LastError;
} Codec;

struct ScriptParser {
    Codec *codec;
};

void SFS_Expression(ScriptParser *parser);
void SFS_AddString(ScriptParser *parser, const char *str);
void SFS_CompoundExpression(ScriptParser *parser);