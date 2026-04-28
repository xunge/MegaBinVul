#include <string.h>
#include <stddef.h>

#define __user
#define EFAULT 14
#define EINVAL 22

struct media_device;
struct media_entity {
    unsigned int id;
    char *name;
    unsigned int type;
    unsigned int revision;
    unsigned int flags;
    unsigned int group_id;
    unsigned short num_pads;
    unsigned short num_links;
    unsigned short num_backlinks;
    struct {
        unsigned int major;
        unsigned int minor;
    } info;
};

struct media_entity_desc {
    unsigned int id;
    char name[32];
    unsigned int type;
    unsigned int revision;
    unsigned int flags;
    unsigned int group_id;
    unsigned short pads;
    unsigned short links;
    union {
        struct {
            unsigned int major;
            unsigned int minor;
        } dev;
        unsigned char raw[184];
    };
};

extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int copy_to_user(void *to, const void *from, unsigned long n);
extern struct media_entity *find_entity(struct media_device *mdev, unsigned int id);