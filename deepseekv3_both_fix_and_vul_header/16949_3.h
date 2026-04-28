#include <string.h>

struct asection {
    unsigned long flags;
    const char *name;
    struct asection *next;
};

struct bfd {
    struct asection *sections;
};

struct dwarf_debug_section {
    const char *uncompressed_name;
    const char *compressed_name;
};

enum {
    debug_info
};

#define GNU_LINKONCE_INFO ".gnu.linkonce.wi."
#define SEC_HAS_CONTENTS 0x100

static int startswith(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

typedef struct asection asection;
typedef struct bfd bfd;