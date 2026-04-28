#include <stddef.h>

typedef void* gnutls_certificate_credentials_t;

extern int weechat_no_gnutls;
extern gnutls_certificate_credentials_t gnutls_xcred;
extern int weechat_debug_core;
extern void gui_chat_printf(void *ptr, const char *text, ...);
extern int network_num_certs;
extern void network_load_ca_files(int force_display);

void gnutls_certificate_free_credentials(gnutls_certificate_credentials_t cred);
void gnutls_certificate_allocate_credentials(gnutls_certificate_credentials_t *cred);
const char *NG_(const char *singular, const char *plural, int count);