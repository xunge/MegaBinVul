#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

typedef struct {
    int LastError;
} Codec;

typedef struct {
    void *bs;
    void *identifiers;
    Codec *codec;
} ScriptParser;

unsigned int gf_get_bit_size(unsigned int val);
unsigned int gf_bs_read_int(void *bs, int nbits);
void gf_bifs_dec_name(void *bs, char *name, ...);
unsigned int gf_list_count(void *list);
void *gf_list_get(void *list, unsigned int index);
void gf_list_add(void *list, void *item);
char *gf_strdup(const char *str);
void SFS_AddString(ScriptParser *parser, char *str);