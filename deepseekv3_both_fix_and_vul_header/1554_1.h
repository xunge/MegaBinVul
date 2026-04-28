#include <stdint.h>

typedef uint32_t u32;

typedef struct {
    int LastError;
} Codec;

typedef struct {
    uint32_t code;
} BitStream;

typedef struct ScriptParser {
    Codec *codec;
    BitStream *bs;
} ScriptParser;

void SFS_Expression(ScriptParser *parser);
void SFS_AddString(ScriptParser *parser, const char *str);
u32 gf_bs_read_int(BitStream *bs, int bits);