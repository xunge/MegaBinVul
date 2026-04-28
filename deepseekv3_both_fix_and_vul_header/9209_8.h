#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int crnc_context;
    int frame_num;
} nbap_com_context_id_t;

typedef struct {
    struct {
        struct {
            int num;
            struct {
                bool visited;
            } flags;
        } *fd;
    } *pinfo;
} asn1_ctx_t;

typedef struct {} tvbuff_t;
typedef struct {} proto_tree;

#define FALSE false
#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))
typedef int gint;
#define _U_

extern void* com_context_map;
extern int node_b_com_context_id;
extern int com_context_id;
extern bool crcn_context_present;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
                                  proto_tree *tree, int hf_index, unsigned min,
                                  unsigned max, int *val, bool flag);
void* g_tree_lookup(void* tree, void* key);
void g_tree_insert(void* tree, void* key, void* value);
#define g_new(type, count) ((type*)malloc(sizeof(type)*(count)))