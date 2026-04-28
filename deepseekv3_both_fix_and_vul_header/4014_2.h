#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

struct ksmbd_user;
struct ksmbd_conn {
    struct nls_table *local_nls;
};
struct smb2_sess_setup_req {
    uint16_t SecurityBufferLength;
    uint16_t SecurityBufferOffset;
};
struct nls_table;

struct authenticate_message {
    struct {
        uint16_t Length;
        uint16_t MaximumLength;
        uint32_t BufferOffset;
    } UserName;
};

#define SMB 0
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ksmbd_debug(type, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define kfree free

typedef uint64_t u64;
typedef uint16_t __le16;
typedef uint32_t __le32;

struct ksmbd_user *ksmbd_login_user(const char *name);
struct authenticate_message *user_authblob(struct ksmbd_conn *conn, struct smb2_sess_setup_req *req);
char *smb_strndup_from_utf16(const char *src, int len, bool ucs2, struct nls_table *nls);