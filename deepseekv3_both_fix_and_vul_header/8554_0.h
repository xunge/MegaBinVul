#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

#define AID_APP 10000

struct str8 {
    const uint16_t *data;
    size_t size;
};

static struct str8 str8(const uint16_t *data, size_t size) {
    struct str8 str;
    str.data = data;
    str.size = size;
    return str;
}

static int check_mac_perms_from_lookup(pid_t spid, uid_t uid, const char *perm, struct str8 name);