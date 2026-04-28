#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct tmComResInfo {
    uint32_t id;
    uint32_t command;
    uint16_t controlselector;
    uint16_t size;
    uint32_t seqno;
};

struct tmComResBusInfo {
    uint32_t m_dwGetWritePos;
    uint32_t m_dwGetReadPos;
    uint32_t m_dwSizeGetRing;
    uint32_t* m_pdwGetRing;
    uint16_t m_wMaxReqSize;
    int lock;
};

struct saa7164_dev {
    struct tmComResBusInfo bus;
};

#define SAA_OK 0
#define SAA_ERR_BAD_PARAMETER 1
#define SAA_ERR_EMPTY 2
#define SAA_ERR_INVALID_COMMAND 3

#define KERN_ERR ""
#define __func__ ""

static inline uint32_t saa7164_readl(uint32_t addr) { return addr; }
static inline void saa7164_writel(uint32_t addr, uint32_t val) { addr = val; }
static inline void saa7164_bus_verify(struct saa7164_dev* dev) {}
static inline void saa7164_bus_dumpmsg(struct saa7164_dev* dev, struct tmComResInfo* msg, void* buf) {}

static inline void mutex_lock(int* lock) { *lock = 1; }
static inline void mutex_unlock(int* lock) { *lock = 0; }

#define __force
#define __le16 uint16_t
#define __le32 uint32_t
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define memcpy_fromio(dest, src, size) memcpy(dest, src, size)
#define printk printf