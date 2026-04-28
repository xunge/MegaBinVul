#include <stdbool.h>
#include <stdint.h>

struct ksmbd_conn {
    uint8_t *request_buf;
};

#define SMB2_COMPRESSION_TRANSFORM_ID 0
#define SMB1_PROTO_NUMBER 0
#define SMB2_PROTO_NUMBER 0 
#define SMB2_TRANSFORM_PROTO_NUM 0

uint32_t *smb2_get_msg(uint8_t *buf);

void pr_err_ratelimited(const char *fmt);

typedef uint32_t __le32;