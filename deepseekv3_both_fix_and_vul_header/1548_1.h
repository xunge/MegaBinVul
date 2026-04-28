#include <stdlib.h>
#include <string.h>

typedef enum {
    GF_OK,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef unsigned int u32;

#define GF_FALSE 0
#define GF_TRUE 1

typedef struct {
    int dec_memory_mode;
    GF_Err LastError;
} GF_BifsDecoder;

typedef struct {
    char *script_text;
} SFScript;

typedef struct {
    void *bs;
} GF_BitStream;

typedef struct {
    int tag;
} GF_Node;

typedef struct {
    GF_BifsDecoder *codec;
    GF_Node *script;
    GF_BitStream *bs;
    u32 length;
    char *string;
    void *identifiers;
    char *new_line;
    int indent;
} ScriptParser;

#define TAG_MPEG4_Script 0

void *gf_list_new();
int gf_list_count(void *list);
void *gf_list_get(void *list, int index);
void gf_list_rem(void *list, int index);
void gf_list_del(void *list);
char *gf_strdup(const char *str);
void gf_free(void *ptr);
void *gf_malloc(size_t size);
int gf_bs_read_int(GF_BitStream *bs, int bits);
int gf_node_get_tag(GF_Node *n);

GF_Err ParseScriptField(ScriptParser *parser);
void SFS_AddString(ScriptParser *parser, const char *str);
void SFS_Identifier(ScriptParser *parser);
void SFS_Arguments(ScriptParser *parser, int flag);
void SFS_Space(ScriptParser *parser);
void SFS_StatementBlock(ScriptParser *parser, int flag);
void SFS_Line(ScriptParser *parser);