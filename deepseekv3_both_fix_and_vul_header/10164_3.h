#include <stdlib.h>
#include <string.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef void* gpointer;

typedef struct xmlNode xmlNode;

typedef struct {
    int* tls_session;  // Changed from void* to int* to allow dereferencing
    gboolean tls_handshake_complete;
    unsigned int auth_timeout;
} crm_remote_t;

typedef struct {
    char *id;
    char *name;
    crm_remote_t *remote;
} crm_client_t;

extern int lrmd_call_id;
extern int crm_remote_ready(crm_remote_t *remote, int timeout);
extern void crm_remote_recv(crm_remote_t *remote, int timeout, int *disconnected);
extern xmlNode* crm_remote_parse_buffer(crm_remote_t *remote);
extern void crm_err(const char *format, ...);
extern void crm_debug(const char *format, ...);
extern void crm_info(const char *format, ...);
extern void crm_trace(const char *format, ...);
extern char* crm_element_value(xmlNode *xml, const char *name);
extern int crm_element_value_int(xmlNode *xml, const char *name, int *dest);
extern void crm_xml_add(xmlNode *xml, const char *name, const char *value);
extern void crm_xml_add_int(xmlNode *xml, const char *name, int value);
extern void free_xml(xmlNode *xml);
extern void process_lrmd_message(crm_client_t *client, int id, xmlNode *request);

#define F_LRMD_REMOTE_MSG_ID "remote_msg_id"
#define F_LRMD_CLIENTNAME "clientname"
#define F_LRMD_CLIENTID "clientid"
#define F_LRMD_CALLID "callid"

#define GNUTLS_E_AGAIN (-1)
#define GNUTLS_E_INTERRUPTED (-2)

// Stub functions to satisfy linker
static int gnutls_handshake(int session) { return 0; }
static void g_source_remove(unsigned int timeout) {}