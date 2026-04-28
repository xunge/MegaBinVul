#include <sys/types.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/queue.h>

struct sshbuf;
struct sshkey;
struct dest_constraint;

typedef struct SocketEntry {
    struct sshbuf *request;
    size_t nsession_ids;
} SocketEntry;

typedef struct Identity {
    struct sshkey *key;
    char *provider;
    char *comment;
    time_t death;
    int confirm;
    struct dest_constraint *dest_constraints;
    size_t ndest_constraints;
    TAILQ_ENTRY(Identity) next;
} Identity;

typedef struct idtab {
    TAILQ_HEAD(idlisthead, Identity) idlist;
    int nentries;
} idtab_struct;

extern idtab_struct *idtab;
extern int lifetime;
extern char *allowed_providers;
extern int remote_add_provider;

int sshbuf_get_cstring(struct sshbuf *, char **, void *);
int parse_key_constraints(struct sshbuf *, void *, time_t *, u_int *, int *, void *, struct dest_constraint **, size_t *);
int pkcs11_add_provider(const char *, const char *, struct sshkey ***, char ***);
Identity *lookup_identity(struct sshkey *);
void *xcalloc(size_t, size_t);
char *xstrdup(const char *);
void sshkey_free(struct sshkey *);
void free_dest_constraints(struct dest_constraint *, size_t);
void send_status(SocketEntry *, int);
time_t monotime(void);
int match_pattern_list(const char *, const char *, int);
void debug2_f(const char *);
void error_fr(int, const char *);
void error_f(const char *);
void verbose(const char *, ...);
void debug_f(const char *, ...);