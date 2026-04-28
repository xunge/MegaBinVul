#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef int krb5_error_code;
typedef void* krb5_context;
typedef void* krb5_pac;

typedef struct {
    int type;
    // Add other principal fields as needed
} krb5_principal_data;
typedef krb5_principal_data* krb5_principal;

typedef struct {
    unsigned int length;
    void* data;
} krb5_data;

typedef struct {
    int type;
    // Add other keyblock fields as needed
} krb5_keyblock;

typedef int krb5_timestamp;

#define KRB5_PRINCIPAL_PARSE_ENTERPRISE 1
#define KRB5_NT_MS_PRINCIPAL 1
#define TRUE 1

struct pac_and_info {
    const unsigned char *data;
    size_t length;
    krb5_timestamp authtime;
    int is_enterprise;
    int is_xrealm;
};

extern char *user;
extern unsigned char saved_pac[1024];
extern unsigned char fuzz1[1024];
extern unsigned char fuzz2[1024];
extern krb5_timestamp authtime;
extern size_t type_1_length;
extern krb5_keyblock member_keyblock;
extern krb5_keyblock kdc_keyblock;
extern char *s4u_principal;
extern char *s4u_enterprise;
extern size_t s4u_logon_info_buffer_len;
extern krb5_keyblock s4u_srv_key;
extern krb5_keyblock s4u_tgt_srv_key;
extern const struct pac_and_info s4u_pacs[];

extern void test_pac_ticket_signature(krb5_context context);
extern void check_pac(krb5_context context, int idx, const void *data, size_t length,
                     krb5_timestamp authtime, krb5_principal p, size_t type_1_length,
                     int is_xrealm, krb5_keyblock *member_keyblock, krb5_keyblock *kdc_keyblock);
extern void err(void *context, int ret, const char *msg);

krb5_error_code krb5_init_context(krb5_context *context);
krb5_error_code krb5_set_default_realm(krb5_context context, const char *realm);
krb5_error_code krb5_parse_name(krb5_context context, const char *name, krb5_principal *principal);
krb5_error_code krb5_parse_name_flags(krb5_context context, const char *name, int flags, krb5_principal *principal);
void krb5_free_principal(krb5_context context, krb5_principal principal);
krb5_error_code krb5_pac_parse(krb5_context context, const unsigned char *buf, size_t len, krb5_pac *pac);
krb5_error_code krb5_pac_init(krb5_context context, krb5_pac *pac);
void krb5_pac_free(krb5_context context, krb5_pac pac);
krb5_error_code krb5_pac_add_buffer(krb5_context context, krb5_pac pac, uint32_t type, const krb5_data *data);
krb5_error_code krb5_pac_get_buffer(krb5_context context, krb5_pac pac, uint32_t type, krb5_data *data);
void krb5_free_data_contents(krb5_context context, krb5_data *data);
krb5_error_code krb5_pac_sign(krb5_context context, krb5_pac pac, krb5_timestamp authtime, krb5_principal principal,
                              krb5_keyblock *server_key, krb5_keyblock *privsvr_key, krb5_data *data);
krb5_error_code krb5_pac_verify(krb5_context context, krb5_pac pac, krb5_timestamp authtime, krb5_principal principal,
                               krb5_keyblock *server_key, krb5_keyblock *privsvr_key);
krb5_error_code krb5_pac_get_types(krb5_context context, krb5_pac pac, size_t *len, uint32_t **types);
krb5_error_code krb5_copy_principal(krb5_context context, krb5_principal inprinc, krb5_principal *outprinc);
krb5_error_code krb5_pac_verify_ext(krb5_context context, krb5_pac pac, krb5_timestamp authtime, krb5_principal principal,
                                   krb5_keyblock *server_key, krb5_keyblock *privsvr_key, int with_realm);
krb5_error_code krb5_pac_sign_ext(krb5_context context, krb5_pac pac, krb5_timestamp authtime, krb5_principal principal,
                                 krb5_keyblock *server_key, krb5_keyblock *privsvr_key, int with_realm, krb5_data *data);
void krb5_free_context(krb5_context context);