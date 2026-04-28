#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct xmpp_stanza_t xmpp_stanza_t;
typedef struct xmpp_ctx_t xmpp_ctx_t;

typedef struct Jid {
    char *barejid;
    char *resourcepart;
} Jid;

#define STANZA_NS_CARBONS "urn:xmpp:carbons:2"
#define STANZA_NS_FORWARD "urn:xmpp:forward:0"
#define STANZA_NS_ENCRYPTED "urn:xmpp:encrypted:0"
#define STANZA_NAME_MESSAGE "message"

#define TRUE 1
#define FALSE 0
typedef int gboolean;
typedef const char gchar;

extern xmpp_stanza_t* xmpp_stanza_get_child_by_ns(xmpp_stanza_t *stanza, const char *ns);
extern const char* xmpp_stanza_get_name(xmpp_stanza_t *stanza);
extern xmpp_stanza_t* xmpp_stanza_get_child_by_name(xmpp_stanza_t *stanza, const char *name);
extern char* xmpp_message_get_body(xmpp_stanza_t *stanza);
extern const char* xmpp_stanza_get_to(xmpp_stanza_t *stanza);
extern const char* xmpp_stanza_get_from(xmpp_stanza_t *stanza);
extern char* xmpp_stanza_get_text(xmpp_stanza_t *stanza);
extern void xmpp_free(xmpp_ctx_t *ctx, void *p);

extern xmpp_ctx_t *connection_get_ctx(void);
extern char *connection_get_fulljid(void);
extern Jid *jid_create(const char *jid_str);
extern void jid_destroy(Jid *jid);
extern void sv_ev_incoming_carbon(const char *from, const char *resource, const char *message, const char *enc_message);
extern void sv_ev_outgoing_carbon(const char *to, const char *message, const char *enc_message);
extern void log_error(const char *format, ...);
extern void log_info(const char *format, ...);
extern void log_warning(const char *format, ...);

static int g_strcmp0(const char *str1, const char *str2) {
    if (str1 == str2) return 0;
    if (!str1) return -1;
    if (!str2) return 1;
    return strcmp(str1, str2);
}