#include <sys/queue.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef unsigned int u_int;

#define SSHKEY_SERIALIZE_INFO 0
#define SSH2_AGENT_IDENTITIES_ANSWER 0
#define SSH_FP_HASH_DEFAULT 0
#define SSH_FP_DEFAULT 0

struct sshbuf {
    /* dummy structure */
};

struct sshkey {
    /* dummy structure */
};

struct sshbuf *sshbuf_new(void);
int sshkey_puts_opts(struct sshkey *, struct sshbuf *, int);
int sshbuf_put_cstring(struct sshbuf *, const char *);
int sshbuf_put_u8(struct sshbuf *, u_int);
int sshbuf_put_u32(struct sshbuf *, u_int);
int sshbuf_putb(struct sshbuf *, struct sshbuf *);
int sshbuf_put_stringb(struct sshbuf *, struct sshbuf *);
void sshbuf_free(struct sshbuf *);
char *sshkey_fingerprint(struct sshkey *, int, int);
char *sshkey_ssh_name(struct sshkey *);

typedef struct SocketEntry {
    struct sshbuf *output;
} SocketEntry;

typedef struct Identity {
    struct sshkey *key;
    char *comment;
    void *dest_constraints;
    u_int ndest_constraints;
    TAILQ_ENTRY(Identity) next;
} Identity;

typedef struct Idtab {
    TAILQ_HEAD(, Identity) idlist;
    u_int nentries;
} Idtab;

extern Idtab *idtab;
extern int identity_permitted(Identity *, SocketEntry *, void *, void *, void *);
extern void debug2_f(const char *, ...);
extern void debug_f(const char *, ...);
extern void fatal_f(const char *, ...);
extern void fatal_fr(int, const char *, ...);
extern void error_fr(int, const char *, ...);
extern void dump_dest_constraints(const char *, void *, u_int);