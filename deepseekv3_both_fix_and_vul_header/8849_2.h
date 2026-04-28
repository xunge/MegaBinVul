#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct monitor {
    void *m_zlib;
};

struct ssh {
    struct kex *kex;
};

struct kex {
    int (*kex[20])(void);
    int (*load_host_public_key)(void);
    int (*load_host_private_key)(void);
    int (*host_key_index)(void);
    int (*sign)(void);
};

struct sshbuf;

#define KEX_DH_GRP1_SHA1 0
#define KEX_DH_GRP14_SHA1 1
#define KEX_DH_GRP14_SHA256 2
#define KEX_DH_GRP16_SHA512 3
#define KEX_DH_GRP18_SHA512 4
#define KEX_DH_GEX_SHA1 5
#define KEX_DH_GEX_SHA256 6
#define KEX_ECDH_SHA2 7
#define KEX_C25519_SHA256 8

extern struct ssh *active_state;
extern struct sshbuf *child_state;

extern int ssh_packet_set_state(struct ssh *, struct sshbuf *);
extern void sshbuf_free(struct sshbuf *);
extern const char *ssh_err(int);
extern void fatal(const char *, ...);

extern struct {
    int compression;
} options;

extern int debug3(const char *, ...);

extern int kexdh_server;
extern int kexgex_server;
extern int kexecdh_server;
extern int kexc25519_server;

extern void *mm_zalloc(size_t);
extern void mm_zfree(void *);

typedef void *(*ssh_packet_comp_alloc_func)(size_t);
typedef void (*ssh_packet_comp_free_func)(void *);
extern int ssh_packet_set_compress_hooks(struct ssh *, void *,
    ssh_packet_comp_alloc_func, ssh_packet_comp_free_func);

extern int get_hostkey_public_by_type;
extern int get_hostkey_private_by_type;
extern int get_hostkey_index;
extern int sshd_hostkey_sign;