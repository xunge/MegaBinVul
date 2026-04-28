#include <sys/types.h>
#include <sys/queue.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define PATH_MAX 4096

#define SSH_AGENT_CONSTRAIN_LIFETIME 1
#define SSH_AGENT_CONSTRAIN_CONFIRM 2

#define KEY_RSA1 1

struct sshbuf;

struct sshkey {
    int type;
};

typedef struct SocketEntry {
    struct sshbuf *request;
} SocketEntry;

typedef struct Identity {
    struct sshkey *key;
    char *provider;
    char *comment;
    time_t death;
    int confirm;
    TAILQ_ENTRY(Identity) next;
} Identity;

typedef struct Idtab {
    TAILQ_HEAD(, Identity) idlist;
    int nentries;
} Idtab;

extern int lifetime;
extern char *pkcs11_whitelist;

time_t monotime(void);
int sshbuf_get_cstring(struct sshbuf *, char **, void *);
int sshbuf_get_u8(struct sshbuf *, u_char *);
int sshbuf_get_u32(struct sshbuf *, u_int *);
size_t sshbuf_len(struct sshbuf *);
const char *ssh_err(int);
int pkcs11_add_provider(const char *, const char *, struct sshkey ***);
struct Idtab *idtab_lookup(int);
struct Identity *lookup_identity(struct sshkey *, int);
void sshkey_free(struct sshkey *);
void *xcalloc(size_t, size_t);
char *xstrdup(const char *);
void send_status(SocketEntry *, int);
void fatal(const char *, ...);
void error(const char *, ...);
void verbose(const char *, ...);
void debug(const char *, ...);
char *realpath(const char *, char *);
int match_pattern_list(const char *, const char *, int);