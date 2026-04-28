#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint32_t __be32;

#define CIPSO_V4_HDR_LEN 8
#define CIPSO_V4_TAG_INVALID 0
#define CIPSO_V4_TAG_MAXCNT 5
#define CIPSO_V4_TAG_RBITMAP 1
#define CIPSO_V4_TAG_RBM_BLEN 4
#define CIPSO_V4_TAG_ENUM 2
#define CIPSO_V4_TAG_ENUM_BLEN 4
#define CIPSO_V4_TAG_RANGE 5
#define CIPSO_V4_TAG_RNG_BLEN 4
#define CIPSO_V4_TAG_LOCAL 128
#define CIPSO_V4_TAG_LOC_BLEN 2
#define IFF_LOOPBACK 0x8

struct cipso_v4_doi {
    u8 tags[5];
};

struct net_device {
    unsigned int flags;
};

struct sk_buff {
    struct net_device *dev;
};

extern int cipso_v4_rbm_strictvalid;
extern struct cipso_v4_doi *cipso_v4_doi_search(__be32 doi);
extern int cipso_v4_map_lvl_valid(const struct cipso_v4_doi *doi_def, u8 level);
extern int cipso_v4_map_cat_rbm_valid(const struct cipso_v4_doi *doi_def, const unsigned char *catmap, u32 catmap_len);
extern int cipso_v4_map_cat_enum_valid(const struct cipso_v4_doi *doi_def, const unsigned char *catlist, u32 catlist_len);
extern int cipso_v4_map_cat_rng_valid(const struct cipso_v4_doi *doi_def, const unsigned char *catlist, u32 catlist_len);
extern __be32 get_unaligned_be32(const void *p);
extern void rcu_read_lock(void);
extern void rcu_read_unlock(void);