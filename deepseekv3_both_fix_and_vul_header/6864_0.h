#include <stdint.h>

struct sftpjob;
struct handleid {
    uint32_t id;
    uint32_t tag;
};

#define SSH_FX_OK 0
#define SSH_FX_BAD_MESSAGE 1

uint32_t sftp_parse_uint32(struct sftpjob *job, uint32_t *val);