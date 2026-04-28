#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int crnc_context;
    int frame_num;
} nbap_com_context_id_t;

typedef struct {} tvbuff_t;
typedef struct {
    struct {
        struct {
            int num;
            struct {
                int visited;
            } flags;
        } *fd;
    } *pinfo;
} asn1_ctx_t;
typedef struct {} proto_tree;

#define FALSE false
#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))
#define _U_
typedef int gint;
#define g_new(type, count) ((type*)malloc(sizeof(type)*(count)))

extern int dissect_per_constrained_integer(tvbuff_t*, int, asn1_ctx_t*, proto_tree*, int, unsigned, unsigned, int*, bool);
extern void* g_tree_lookup(void*, void*);
extern void g_tree_insert(void*, void*, void*);

extern int node_b_com_context_id;
extern bool crcn_context_present;
extern void* com_context_map;
extern int com_context_id;