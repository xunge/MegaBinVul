#include <string.h>

struct rtattr {
    unsigned short rta_len;
    unsigned short rta_type;
};

#define RTA_ALIGN(len) (((len) + 3) & ~3)
#define RTA_LENGTH(len) (sizeof(struct rtattr) + (len))
#define RTA_DATA(rta) ((void*)(((char*)(rta)) + sizeof(struct rtattr)))

struct sk_buff;
void *skb_put(struct sk_buff *skb, unsigned int len);