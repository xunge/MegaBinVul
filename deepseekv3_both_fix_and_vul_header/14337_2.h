#include <stdlib.h>

typedef struct {
    int LastError;
} Codec;

typedef struct {
    void* bs;
    Codec* codec;
} ScriptParser;

void gf_bifs_dec_name(void* bs, char* name, ...);
void SFS_AddString(ScriptParser* parser, char* name);