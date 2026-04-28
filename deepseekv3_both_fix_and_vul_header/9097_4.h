#include <stdlib.h>
#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct {
    struct pinfo {
        struct frame_data {
            int num;
            struct {
                unsigned visited:1;
            } flags;
        } *fd;
    } *pinfo;
} asn1_ctx_t;

typedef struct {
    int crnc_context;
    int frame_num;
} nbap_com_context_id_t;

#define FALSE 0
#define TRUE 1
#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))
#define g_new(type, n) ((type*)malloc(sizeof(type)*(n)))
#define g_tree_lookup(tree, key) NULL
#define g_tree_insert(tree, key, val) 

extern int crcn_context_present;
extern int node_b_com_context_id;
extern int com_context_id;
extern void* com_context_map;

#define _U_ __attribute__((unused))