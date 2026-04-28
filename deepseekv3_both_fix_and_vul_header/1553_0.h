#include <stdio.h>
#include <stdlib.h>

typedef struct ScriptParser ScriptParser;
typedef struct BitStream BitStream;
typedef struct Codec Codec;

struct Codec {
    int LastError;
};

struct BitStream {
    int (*read_int)(BitStream*, int);
};

struct ScriptParser {
    Codec* codec;
    BitStream* bs;
};

int gf_bs_read_int(BitStream* bs, int bits);
void SFS_Expression(ScriptParser* parser);
void SFS_AddString(ScriptParser* parser, const char* str);