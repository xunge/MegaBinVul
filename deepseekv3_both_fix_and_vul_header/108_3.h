#include <stdint.h>
#include <errno.h>

typedef uint32_t u32;

struct nft_ctx;
struct nlattr;

struct nft_set {
    unsigned int dtype;
    unsigned int dlen;
};

struct nft_data_desc {
    unsigned int type;
    unsigned int len;
};

struct nft_data;

#define NFT_DATA_VALUE_MAXLEN 0
#define NFT_DATA_VERDICT 1
#define NFT_DATA_VALUE 2
#define EINVAL 22

extern int nft_data_init(struct nft_ctx *ctx, struct nft_data *data, int len, struct nft_data_desc *desc, struct nlattr *attr);
extern void nft_data_release(struct nft_data *data, int type);