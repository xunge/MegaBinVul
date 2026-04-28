#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

struct sshkey;
struct sshbuf;
struct dest_constraint;

typedef struct Identity {
    struct sshkey *key;
    char *provider;
    char *comment;
    time_t death;
    int confirm;
    struct dest_constraint *dest_constraints;
    size_t ndest_constraints;
    struct Identity *next;
} Identity;

typedef struct idtab {
    struct Identity *idlist;
    int nentries;
} idtab_struct;

typedef struct SocketEntry {
    struct sshbuf *request;
    int nsession_ids;
} SocketEntry;

extern int remote_add_provider;
extern char *allowed_providers;
extern int lifetime;
extern idtab_struct *idtab;
extern int debug2_f(const char *, ...);
extern int error_fr(int, const char *, ...);
extern int error_f(const char *, ...);
extern int verbose(const char *, ...);
extern int debug_f(const char *, ...);
extern int sshbuf_get_cstring(struct sshbuf *, char **, void *);
extern int parse_key_constraints(struct sshbuf *, char **, time_t *, u_int *, int *, char **, struct dest_constraint **, size_t *);
extern char *realpath(const char *, char *);
extern int match_pattern_list(const char *, const char *, int);
extern time_t monotime(void);
extern int pkcs11_add_provider(const char *, const char *, struct sshkey ***, char ***);
extern Identity *lookup_identity(struct sshkey *);
extern void *xcalloc(size_t, size_t);
extern char *xstrdup(const char *);
extern void sshkey_free(struct sshkey *);
extern void free_dest_constraints(struct dest_constraint *, size_t);
extern void send_status(SocketEntry *, int);

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field = NULL; \
    if ((*(head)) == NULL) { \
        (*(head)) = (elm); \
    } else { \
        struct Identity *last = (*(head)); \
        while (last->field != NULL) \
            last = last->field; \
        last->field = (elm); \
    } \
} while (0)