#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
typedef uint16_t u16;

struct super_block;

struct hfs_find_data {
    void *search_key;
};

struct hfsplus_cat_entry {
    u16 type;
    struct {
        u32 parentID;
        struct {
            u16 length;
            void *unicode;
        } nodeName;
    } thread;
};

#define HFSPLUS_FOLDER_THREAD 0x0001
#define HFSPLUS_FILE_THREAD 0x0002
#define EIO 5
#define KERN_ERR ""
#define printk printf

static inline u16 be16_to_cpu(u16 val) { return val; }
static inline u32 be32_to_cpu(u32 val) { return val; }

void hfsplus_cat_build_key(struct super_block *sb, void *key, u32 cnid, void *unused);
void hfsplus_cat_build_key_uni(void *key, u32 parentID, struct hfsplus_cat_entry *entry);
int hfs_brec_read(struct hfs_find_data *fd, struct hfsplus_cat_entry *rec, int rec_len);
int hfs_brec_find(struct hfs_find_data *fd);

typedef struct hfsplus_cat_entry hfsplus_cat_entry;