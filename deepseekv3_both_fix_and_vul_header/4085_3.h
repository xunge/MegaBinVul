#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef bool gboolean;
typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    int dummy;  // Placeholder for ber_choice_t structure
} ber_choice_t;

#define _U_ __attribute__((unused))

extern const ber_choice_t SubjectName_choice[];
extern int ett_x509af_SubjectName;

const char* x509if_get_last_dn(void);
int dissect_ber_choice(asn1_ctx_t* actx, proto_tree* tree, tvbuff_t* tvb, int offset, 
                      const ber_choice_t* choice, int hf_index, int ett, void* data);
void proto_item_append_text(proto_item* item, const char* format, ...);
proto_item* proto_item_get_parent(proto_tree* tree);