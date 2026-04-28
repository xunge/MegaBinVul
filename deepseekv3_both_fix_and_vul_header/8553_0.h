#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

#define AID_APP 10000

struct str8 {
    const uint16_t *data;
    size_t len;
};

static struct str8 str8(const uint16_t *name, size_t name_len) {
    struct str8 s = {name, name_len};
    return s;
}

static int check_mac_perms_from_lookup(pid_t spid, uid_t uid, const char *perm, struct str8 name);