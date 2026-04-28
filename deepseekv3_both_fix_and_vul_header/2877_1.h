#include <stdlib.h>
#include <string.h>

struct nlattr {
    unsigned short nla_len;
    unsigned short nla_type;
};

struct xfrm_replay_state_esn {
    unsigned int bmp_len;
    unsigned int replay_window;
    unsigned int seq;
    unsigned int seq_hi;
    unsigned int bitmap[0];
};

#define GFP_KERNEL 0
#define ENOMEM 12

static inline void *kmemdup(const void *src, size_t len, int gfp)
{
    void *p = malloc(len);
    if (p)
        memcpy(p, src, len);
    return p;
}

static inline void kfree(void *p)
{
    free(p);
}

static inline void *nla_data(const struct nlattr *nla)
{
    return (void *)nla + sizeof(struct nlattr);
}

static inline size_t xfrm_replay_state_esn_len(const struct xfrm_replay_state_esn *esn)
{
    return sizeof(struct xfrm_replay_state_esn) + esn->bmp_len * sizeof(unsigned int);
}