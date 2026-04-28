#include <string.h>
#include <stdlib.h>

typedef struct _tvbuff tvbuff_t;
typedef struct _proto_tree proto_tree;
typedef struct _packet_info packet_info;
typedef unsigned char guint8;
typedef int gint;

#define ENC_UTF_16 0
#define ENC_LITTLE_ENDIAN 0
#define _U_ 

char* tvb_get_string_enc(void* pool, tvbuff_t* tvb, int offset, int length, int encoding);
int tvb_captured_length_remaining(tvbuff_t* tvb, int offset);
void proto_tree_add_string(proto_tree* tree, int hf, tvbuff_t* tvb, int start, int length, const char* str);
char* g_strdup(const char* str);
void g_free(void* ptr);