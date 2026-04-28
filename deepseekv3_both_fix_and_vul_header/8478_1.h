#include <string.h>
#include <stddef.h>

#define IDLEN 9
#define CLICAP_SASL 0
#define ERR_SASLABORTED 0
#define ERR_SASLTOOLONG 0

struct Client {
    char id[IDLEN + 1];
    char *name;
    char *host;
    char *sockhost;
    char *certfp;
    struct LocalClient {
        char sasl_agent[IDLEN + 1];
        int sasl_complete;
        int sasl_out;
    } *localClient;
    struct Server {
        char *name;
    } *servptr;
};

struct ConfigFileEntry {
    char *sasl_service;
};

extern struct ConfigFileEntry ConfigFileEntry;
extern struct Client me;

#define IsCapable(client, cap) 0
#define IsService(client) 0
#define EmptyString(str) (!(str) || !*(str))

static void exit_client(struct Client *a, struct Client *b, struct Client *c, const char *msg);
static struct Client *find_named_client(const char *name);
static const char *form_str(int numeric);
static char *generate_uid(void);
static void add_to_id_hash(const char *id, struct Client *client);
static struct Client *find_id(const char *id);
static void sendto_one(struct Client *target, const char *format, ...);
static size_t rb_strlcpy(char *dst, const char *src, size_t siz);