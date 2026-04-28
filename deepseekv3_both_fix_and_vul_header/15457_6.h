#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define TAILQ_ENTRY(type) struct { struct type *tqe_next; struct type **tqe_prev; }
#define TAILQ_HEAD(name, type) struct name { struct type *tqh_first; struct type **tqh_last; }

struct sshkey;
struct sshbuf;

struct dest_constraint {
    /* definition depends on implementation */
};

struct Identity {
    struct sshkey *key;
    char *comment;
    time_t death;
    int confirm;
    char *sk_provider;
    struct dest_constraint *dest_constraints;
    size_t ndest_constraints;
    TAILQ_ENTRY(Identity) next;
};

struct Idtab {
    TAILQ_HEAD(, Identity) idlist;
    size_t nentries;
};

typedef struct SocketEntry {
    struct sshbuf *request;
    size_t nsession_ids;
} SocketEntry;

#define SSH_ERR_INTERNAL_ERROR (-1)
#define PATH_MAX 4096
#define SSH_FP_HASH_DEFAULT 0
#define SSH_FP_DEFAULT 0

extern struct Idtab *idtab;
extern u_int lifetime;
extern int remote_add_provider;
extern const char *allowed_providers;

/* Function prototypes */
int sshkey_private_deserialize(struct sshbuf *, struct sshkey **);
int sshbuf_get_cstring(struct sshbuf *, char **, void *);
int parse_key_constraints(struct sshbuf *, struct sshkey *, time_t *, u_int *, int *, char **, struct dest_constraint **, size_t *);
int sshkey_is_sk(struct sshkey *);
const char *sshkey_type(struct sshkey *);
void sshbuf_reset(struct sshbuf *);
int sshkey_shield_private(struct sshkey *);
time_t monotime(void);
struct Identity *lookup_identity(struct sshkey *);
int identity_permitted(struct Identity *, SocketEntry *, void *, void *, void *);
void sshkey_free(struct sshkey *);
void free_dest_constraints(struct dest_constraint *, size_t);
char *sshkey_fingerprint(struct sshkey *, int, int);
const char *sshkey_ssh_name(struct sshkey *);
void send_status(SocketEntry *, int);
void debug2_f(const char *);
void error_fr(int, const char *);
void error_f(const char *);
void error(const char *, ...);
void verbose(const char *, ...);
void fatal_f(const char *);
void debug_f(const char *, ...);
void *xcalloc(size_t, size_t);
char *xstrdup(const char *);
int match_pattern_list(const char *, const char *, int);

/* Queue macros */
#define TAILQ_INIT(head) do { \
    (head)->tqh_first = NULL; \
    (head)->tqh_last = &(head)->tqh_first; \
} while (0)

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field.tqe_next = NULL; \
    (elm)->field.tqe_prev = (head)->tqh_last; \
    *(head)->tqh_last = (elm); \
    (head)->tqh_last = &(elm)->field.tqe_next; \
} while (0)

/* Add this typedef to make Identity usable without struct keyword */
typedef struct Identity Identity;