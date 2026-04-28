#include <time.h>
#include <string.h>
#include <stdlib.h>

#define SPICE_MAX_PASSWORD_LENGTH 256
#define RSA_PKCS1_OAEP_PADDING 4
#define SPICE_LINK_ERR_PERMISSION_DENIED 1

typedef struct RSA {
    int dummy;
} RSA;

typedef struct TicketingInfo {
    RSA *rsa;
    int rsa_size;
    struct {
        unsigned char *encrypted_data;
    } encrypted_ticket;
} TicketingInfo;

typedef struct RedLinkInfo {
    TicketingInfo tiTicketing;
    int skip_auth;
} RedLinkInfo;

typedef struct {
    char password[256];
    time_t expiration_time;
} TicketAuth;

static TicketAuth taTicket;
static int ticketing_enabled;

void spice_warning(const char *fmt, ...);
void *g_malloc0(size_t size);
void g_free(void *ptr);
int RSA_size(RSA *rsa);
int RSA_private_decrypt(int flen, unsigned char *from, unsigned char *to, RSA *rsa, int padding);
char *ERR_error_string(unsigned long e, char *buf);
unsigned long ERR_get_error(void);
void reds_handle_link(RedLinkInfo *link);
void reds_send_link_result(RedLinkInfo *link, int err);
void reds_link_free(RedLinkInfo *link);