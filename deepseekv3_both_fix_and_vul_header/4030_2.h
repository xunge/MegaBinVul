#include <sys/types.h>
#include <sys/queue.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

struct dest_constraint;
struct sshkey;
struct sshbuf;

typedef struct SocketEntry {
    struct sshbuf *request;
    size_t nsession_ids;
} SocketEntry;

typedef struct Identity {
    struct sshkey *key;
    char *comment;
    time_t death;
    int confirm;
    char *sk_provider;
    struct dest_constraint *dest_constraints;
    size_t ndest_constraints;
    TAILQ_ENTRY(Identity) next;
} Identity;

typedef struct IdTab {
    TAILQ_HEAD(, Identity) idlist;
    size_t nentries;
} IdTab;

extern int remote_add_provider;
extern time_t lifetime;
extern char *allowed_providers;
extern IdTab *idtab;
extern const int SSH_ERR_INTERNAL_ERROR;
extern const int SSH_FP_HASH_DEFAULT;
extern const int SSH_FP_DEFAULT;

int sshkey_private_deserialize(struct sshbuf *, struct sshkey **);
int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
void sshbuf_reset(struct sshbuf *);
int parse_key_constraints(struct sshbuf *, struct sshkey *, time_t *, u_int *, int *, char **, struct dest_constraint **, size_t *);
int sshkey_is_sk(struct sshkey *);
const char *sshkey_type(struct sshkey *);
char *realpath(const char *, char *);
int match_pattern_list(const char *, const char *, int);
int sshkey_shield_private(struct sshkey *);
time_t monotime(void);
Identity *lookup_identity(struct sshkey *);
void *xcalloc(size_t, size_t);
char *xstrdup(const char *);
int identity_permitted(Identity *, SocketEntry *, const char *, const char *, const char *);
void sshkey_free(struct sshkey *);
void free_dest_constraints(struct dest_constraint *, size_t);
char *sshkey_fingerprint(struct sshkey *, int, int);
const char *sshkey_ssh_name(struct sshkey *);
void send_status(SocketEntry *, int);
void debug2_f(const char *, ...);
void error_fr(int, const char *, ...);
void error_f(const char *, ...);
void error(const char *, ...);
void debug_f(const char *, ...);
void verbose(const char *, ...);
void fatal_f(const char *, ...);