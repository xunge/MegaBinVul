typedef int gboolean;

typedef struct _gp_tcapsrt_info {
    int ope;
} gp_tcapsrt_info_t;

extern gp_tcapsrt_info_t *gp_tcapsrt_info;

#define TC_ABORT 0
#define _U_ 

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct column_info column_info;

typedef struct {
    struct {
        column_info *cinfo;
    } *pinfo;
} asn1_ctx_t;

extern int dissect_ber_sequence(gboolean, asn1_ctx_t *, proto_tree *, tvbuff_t *, int, void *, int, int);

#define ett_tcap_Abort 0
#define COL_INFO 0
extern void col_set_str(column_info *cinfo, int column, const char *str);

extern const void *Abort_sequence;