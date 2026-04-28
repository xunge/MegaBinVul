#include <stdint.h>
#include <string.h>

#define AVC_DEBUG_APPLICATION_PMT 0x1
#define AVC_CTYPE_CONTROL 0x0
#define AVC_SUBUNIT_TYPE_TUNER 0x0
#define AVC_OPCODE_VENDOR 0x0
#define EN50221_LIST_MANAGEMENT_ONLY 0x0
#define SFE_VENDOR_DE_COMPANYID_0 0x0
#define SFE_VENDOR_DE_COMPANYID_1 0x0
#define SFE_VENDOR_DE_COMPANYID_2 0x0
#define SFE_VENDOR_OPCODE_HOST2CA 0x0
#define SFE_VENDOR_TAG_CA_PMT 0x0
#define AVC_RESPONSE_ACCEPTED 0x0
#define EINVAL 22
#define EACCES 13

struct firedtv {
    char *avc_data;
    int avc_data_length;
    int subunit;
    void *device;
    void *avc_mutex;
};

struct avc_command_frame {
    unsigned char ctype;
    unsigned char subunit;
    unsigned char opcode;
    unsigned char operand[256];
};

struct avc_response_frame {
    unsigned char response;
};

extern int avc_debug;
extern int avc_write(struct firedtv *fdtv);
extern void debug_pmt(char *msg, int length);
extern void pad_operands(struct avc_command_frame *c, int write_pos);
extern void mutex_lock(void *mutex);
extern void mutex_unlock(void *mutex);
extern void dev_info(void *device, const char *fmt, ...);
extern void dev_err(void *device, const char *fmt, ...);
extern uint32_t crc32_be(uint32_t crc, const void *buf, size_t len);
#define unlikely(x) (x)
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))