#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct sk_buff {
    void *data;
};

struct nfc_dev {
    u32 idx;
};

struct genl_family {
    int dummy;
} nfc_genl_family;

#define NLMSG_DEFAULT_SIZE 1024
#define GFP_ATOMIC 0
#define GFP_KERNEL 0
#define ENOMEM 1
#define EMSGSIZE 2

#define NFC_CMD_FW_DOWNLOAD 0
#define NFC_ATTR_FIRMWARE_NAME 0
#define NFC_ATTR_FIRMWARE_DOWNLOAD_STATUS 1
#define NFC_ATTR_DEVICE_INDEX 2

struct sk_buff* nlmsg_new(int size, int flags);
void nlmsg_free(struct sk_buff *skb);
void* genlmsg_put(struct sk_buff *skb, u32 port, u32 seq, 
                 struct genl_family *family, int flags, u8 cmd);
void genlmsg_end(struct sk_buff *skb, void *hdr);
int genlmsg_multicast(struct genl_family *family, struct sk_buff *skb,
                     u32 port, u32 group, int flags);
int nla_put_string(struct sk_buff *skb, int attrtype, const char *str);
int nla_put_u32(struct sk_buff *skb, int attrtype, u32 value);