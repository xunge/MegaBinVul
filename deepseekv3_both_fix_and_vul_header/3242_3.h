#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define IPA_SETADP_SET_SNMP_CONTROL 0
#define QETH_BUFSIZE 4096
#define IPA_PDU_HEADER_SIZE 32
#define QETH_SNMP_SETADP_CMDLENGTH 64
#define QETH_SETADP_BASE_LEN 128
#define EOPNOTSUPP 1
#define EFAULT 2
#define EINVAL 3
#define ENOMEM 4
#define GFP_KERNEL 0
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))
#define __user

struct qeth_card {
    struct {
        int guestlan;
    } info;
    struct {
        int layer2;
    } options;
};

struct qeth_cmd_buffer {
    char *data;
};

struct qeth_ipa_cmd {
    struct {
        struct {
            struct {
                char snmp[0];
            } data;
        } setadapterparms;
    } data;
};

struct qeth_snmp_ureq {
    struct {
        int data_len;
    } hdr;
    char cmd[0];
};

struct qeth_snmp_ureq_hdr {
    int dummy;
};

struct qeth_ipacmd_hdr {
    int dummy;
};

struct qeth_ipacmd_setadpparms_hdr {
    int dummy;
};

struct qeth_arp_query_info {
    unsigned int udata_len;
    unsigned int udata_offset;
    char *udata;
};

void *memdup_user(const void *src, size_t len);
int copy_from_user(void *dst, const void *src, size_t len);
int copy_to_user(void *dst, const void *src, size_t len);
void *kzalloc(size_t size, int flags);
void kfree(void *ptr);

int qeth_adp_supported(struct qeth_card *card, int cmd);
struct qeth_cmd_buffer *qeth_get_adapter_cmd(struct qeth_card *card, int cmd, int len);
int qeth_send_ipa_snmp_cmd(struct qeth_card *card, struct qeth_cmd_buffer *iob, int len, void (*callback)(void *), void *data);
void qeth_snmp_command_cb(void *data);

#define QETH_CARD_TEXT(card, level, text)
#define QETH_DBF_MESSAGE(level, format, ...)
#define QETH_CARD_IFNAME(card) ""