#include <stdint.h>

typedef struct QEMUFile QEMUFile;

struct SSISlave {
    int cs;
};

struct ssi_sd_state {
    int mode;
    int cmd;
    int cmdarg[4];
    int response[5];
    int arglen;
    int response_pos;
    int stopping;
};

#define SSI_SLAVE(obj) ((struct SSISlave *)(obj))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define EINVAL 22

enum {
    SSI_SD_CMDARG,
    SSI_SD_RESPONSE
};

static inline uint32_t qemu_get_be32(QEMUFile *f) {
    uint32_t val;
    return val;
}

typedef struct SSISlave SSISlave;
typedef struct ssi_sd_state ssi_sd_state;