#include <stdint.h>

typedef int gboolean;
typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t; 
typedef struct proto_tree proto_tree;

typedef struct {
    const char *name;
    int (*dissector)(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int);
    int hf_id;
    int ett;
} ber_sequence_t;

extern int dissect_ber_sequence(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, const ber_sequence_t*, int, int);
extern void x509af_export_publickey(tvbuff_t*, asn1_ctx_t*, int, int);

extern const ber_sequence_t SubjectPublicKeyInfo_sequence[];
extern int ett_x509af_SubjectPublicKeyInfo;

#define _U_ __attribute__((unused))