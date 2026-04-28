#include <stdint.h>
#include <stdlib.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    unsigned int visited;
} fd_flags_t;

typedef struct {
    fd_flags_t flags;
    int num;
} fd_t;

typedef struct {
    fd_t *fd;
} pinfo_t;

typedef struct asn1_ctx_t {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct nbap_com_context_id_t {
    int crnc_context;
    int frame_num;
} nbap_com_context_id_t;

#define FALSE 0
#define _U_
typedef int gint;
#define GINT_TO_POINTER(i) ((void*)(long)(i))
#define g_new(type, count) ((type*)malloc(sizeof(type)*(count)))

extern int node_b_com_context_id;
extern int crcn_context_present;
extern int com_context_id;
extern void* com_context_map;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
                                  proto_tree *tree, int hf_index, unsigned int min,
                                  unsigned int max, int *value, int flag);
void* g_tree_lookup(void *tree, void *key);
void g_tree_insert(void *tree, void *key, void *value);