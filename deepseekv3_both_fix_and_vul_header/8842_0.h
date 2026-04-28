#include <stddef.h>

#define MODE_MAX 2
#define __func__ __FUNCTION__

struct sshcomp {
    int enabled;
};

struct sshkeys {
    struct sshcomp comp;
};

struct sshstate {
    int after_authentication;
    int rekeying;
    struct sshkeys *newkeys[MODE_MAX];
};

struct ssh {
    struct sshstate *state;
};

extern int debug(const char *fmt, ...);
extern int ssh_packet_init_compression(struct ssh *ssh);