#include <stdint.h>
#include <string.h>
#include <stddef.h>

struct create_context {
    uint32_t Next;
    uint16_t NameOffset;
    uint16_t NameLength;
    uint16_t DataOffset;
    uint16_t Reserved;
    uint32_t DataLength;
    uint8_t Buffer[1];
};

struct smb2_create_req {
    uint32_t CreateContextsOffset;
    uint32_t CreateContextsLength;
};

#define ERR_PTR(x) ((void *)(long)(x))
#define EINVAL 22

static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
typedef uint64_t u64;