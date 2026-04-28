#include <stdint.h>
#include <linux/types.h>

#define SMB2_HEADER_STRUCTURE_SIZE 64
#define NUMBER_OF_SMB2_COMMANDS 256
#define SMB2_OPLOCK_BREAK_HE 0x02
#define OP_BREAK_STRUCT_SIZE_20 24
#define OP_BREAK_STRUCT_SIZE_21 36
#define SMB2_LOCK_HE 0x0A
#define SMB2_NEGOTIATE_HE 0x00
#define SMB2_ERROR_STRUCTURE_SIZE2_LE 9
#define __SMB2_HEADER_STRUCTURE_SIZE 64
#define SMB2_GLOBAL_CAP_LARGE_MTU 0x00000001
#define STATUS_INVALID_PARAMETER 0xC000000D
#define SMB 0

struct smb2_hdr {
    __u32 NextCommand;
    __u16 StructureSize;
    __u16 Command;
    __u64 MessageId;
    __u32 Status;
};

struct smb2_pdu {
    struct smb2_hdr hdr;
    __u16 StructureSize2;
};

struct smb2_lock_element {
    __u8 dummy;
};

struct ksmbd_work {
    void *request_buf;
    unsigned int next_smb2_rcv_hdr_off;
    struct {
        struct {
            __u32 capabilities;
        } *vals;
        struct {
            int (*set_rsp_status)(struct ksmbd_work *, __u32);
        } *ops;
    } *conn;
};

static inline __u16 le16_to_cpu(__u16 val) { return val; }
static inline __u32 le32_to_cpu(__u32 val) { return val; }
static inline __u64 le64_to_cpu(__u64 val) { return val; }
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

extern struct smb2_pdu *ksmbd_req_buf_next(struct ksmbd_work *);
extern __u32 get_rfc1002_len(void *);
extern int check_smb2_hdr(struct smb2_hdr *);
extern int smb2_calc_size(struct smb2_hdr *, __u32 *);
extern int smb2_validate_credit_charge(void *, struct smb2_hdr *);
extern void ksmbd_debug(int, const char *, ...);
extern void pr_err_ratelimited(const char *, ...);
extern __u16 smb2_req_struct_sizes[];