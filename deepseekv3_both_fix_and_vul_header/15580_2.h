#include <stdint.h>
#include <time.h>

#define noinline_for_stack __attribute__((noinline))

enum nft_meta_keys {
    NFT_META_TIME_NS,
    NFT_META_TIME_DAY, 
    NFT_META_TIME_HOUR
};

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;
typedef int64_t time64_t;

void nft_reg_store64(u32 *dest, u64 val);
void nft_reg_store8(u32 *dest, u8 val);
u32 nft_meta_hour(time64_t time);
u8 nft_meta_weekday(void);
u64 ktime_get_real_ns(void);
time64_t ktime_get_real_seconds(void);