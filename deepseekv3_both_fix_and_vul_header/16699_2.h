#include <stddef.h>

typedef struct Slapi_PBlock Slapi_PBlock;
typedef struct Slapi_Value {
    int dummy;
} Slapi_Value;
typedef struct Slapi_Attr Slapi_Attr;
typedef struct Slapi_DN Slapi_DN;
typedef struct Slapi_Entry Slapi_Entry;
typedef struct dse dse;
struct berval {
    unsigned long bv_len;
    char *bv_val;
};

#define SLAPI_PLUGIN_PRIVATE 0
#define SLAPI_BIND_TARGET_SDN 0
#define SLAPI_BIND_METHOD 0
#define SLAPI_BIND_CREDENTIALS 0
#define SLAPI_PB_RESULT_TEXT 0
#define SLAPI_BIND_FAIL 0
#define SLAPI_BIND_SUCCESS 0
#define DSE_USE_LOCK 0

#define LDAP_OPERATIONS_ERROR 0
#define LDAP_SUCCESS 0
#define LDAP_INVALID_CREDENTIALS 0
#define LDAP_NO_SUCH_OBJECT 0
#define LDAP_INAPPROPRIATE_AUTH 0
#define LDAP_STRONG_AUTH_NOT_SUPPORTED 0
#define LDAP_AUTH_SIMPLE 0

typedef unsigned long ber_tag_t;

extern int slapi_pblock_get(Slapi_PBlock *pb, int type, void *out);
extern int slapi_send_ldap_result(Slapi_PBlock *pb, int err, char *matched, char *info, int nentries, char **refs);
extern int slapi_pblock_set(Slapi_PBlock *pb, int type, void *in);
extern Slapi_Entry *dse_get_entry_copy(struct dse *pdse, Slapi_DN *sdn, int flags);
extern int slapi_entry_attr_find(Slapi_Entry *e, char *type, Slapi_Attr **attr);
extern Slapi_Value **attr_get_present_values(Slapi_Attr *attr);
extern void slapi_value_init_berval(Slapi_Value *v, struct berval *bv);
extern int slapi_pw_find_sv(Slapi_Value **bvals, Slapi_Value *cv);
extern void value_done(Slapi_Value *v);
extern void slapi_entry_free(Slapi_Entry *e);