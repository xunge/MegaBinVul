#include <stdint.h>
#include <stddef.h>

struct sk_buff;
struct genl_info {
    void **attrs;
    int snd_portid;
    int snd_seq;
};
struct nfc_dev {
    struct {
        int dev;
    } dev;
};
struct nfc_llcp_local;

#define NFC_ATTR_DEVICE_INDEX 0
#define NFC_ATTR_FIRMWARE_NAME 1
#define EINVAL 22
#define ENODEV 19
#define ENOMEM 12
#define GFP_KERNEL 0
#define NLMSG_DEFAULT_SIZE 1024

typedef uint32_t u32;

int nla_get_u32(void* attr);
struct nfc_dev* nfc_get_device(u32 idx);
void device_lock(void* dev);
void device_unlock(void* dev);
struct nfc_llcp_local* nfc_llcp_find_local(struct nfc_dev* dev);
void nfc_put_device(struct nfc_dev* dev);
struct sk_buff* nlmsg_new(size_t size, int flags);
void nlmsg_free(struct sk_buff* skb);
int nfc_genl_send_params(struct sk_buff* msg, struct nfc_llcp_local* local, int portid, int seq);
int genlmsg_reply(struct sk_buff* msg, struct genl_info* info);