#include <string.h>
#include <stdint.h>

#define EINVAL 22
#define EFAULT 14

struct media_device;
struct media_entity;
struct media_links_enum;

struct media_pad_desc {
    uint32_t entity;
    uint32_t index;
    uint32_t flags;
};

struct media_link_desc {
    struct media_pad_desc source;
    struct media_pad_desc sink;
    uint32_t flags;
};

struct media_pad {
    struct media_entity *entity;
    unsigned int index;
};

struct media_link {
    struct media_pad *source;
    struct media_pad *sink;
    unsigned int flags;
};

struct media_entity {
    unsigned int num_pads;
    struct media_pad *pads;
    unsigned int num_links;
    struct media_link *links;
};

struct media_links_enum {
    uint32_t entity;
    struct media_pad_desc *pads;
    struct media_link_desc *links;
};

static inline int copy_to_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline struct media_entity *find_entity(struct media_device *mdev, uint32_t id) {
    return NULL;
}

static inline void media_device_kpad_to_upad(struct media_pad *kpad, struct media_pad_desc *upad) {
    upad->entity = (uintptr_t)kpad->entity;
    upad->index = kpad->index;
    upad->flags = 0;
}

#define __user