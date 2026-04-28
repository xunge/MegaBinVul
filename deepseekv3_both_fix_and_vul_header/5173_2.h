typedef int gboolean;

typedef struct _tvbuff_t tvbuff_t;
typedef struct _proto_tree proto_tree;

typedef struct _packet_info {
    int cinfo;
} packet_info;

typedef struct _asn1_ctx_t {
    packet_info *pinfo;
} asn1_ctx_t;

typedef struct _gp_tcapsrt_info {
    int ope;
} gp_tcapsrt_info_t;

extern gp_tcapsrt_info_t *gp_tcapsrt_info;

#define TC_END 0
#define _U_
#define COL_INFO 0

extern int dissect_ber_sequence(gboolean, asn1_ctx_t *, proto_tree *, tvbuff_t *, int, void *, int, int);

extern void *End_sequence;
extern int ett_tcap_End;
extern void col_set_str(int, const char *, const char *);