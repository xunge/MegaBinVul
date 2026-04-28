#include <string.h>

typedef void* gss_OID;

struct gss_config {
    void* gss_accept_sec_context;
    void* gss_init_sec_context;
    void* gss_delete_sec_context;
    void* gss_acquire_cred;
    void* gssspi_acquire_cred_with_password;
};

struct gss_mech_config {
    struct gss_config* mech;
    const char* mechNameStr;
    gss_OID mech_type;
};

extern struct gss_config krb5_mechanism;
extern struct gss_config iakerb_mechanism;
extern void* gss_mech_iakerb;
extern void* iakerb_gss_accept_sec_context;
extern void* iakerb_gss_init_sec_context;
extern void* iakerb_gss_delete_sec_context;
extern void* iakerb_gss_acquire_cred;
extern void* iakerb_gss_acquire_cred_with_password;
extern void gssint_register_mechinfo(struct gss_mech_config*);