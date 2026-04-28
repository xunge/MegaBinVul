#include <stdlib.h>
#include <stddef.h>

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct gfs2_sbd {
    struct rb_root sd_rindex_tree;
};

struct gfs2_rgrpd {
    struct rb_node rd_node;
    struct gfs2_glock *rd_gl;
    void *rd_bits;
};

struct gfs2_glock {
    struct {
        int lock;
    } gl_lockref;
    void *gl_object;
};

static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }

extern struct rb_node *rb_first(const struct rb_root *root);
extern void rb_erase(struct rb_node *node, struct rb_root *root);
#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

extern struct kmem_cache *gfs2_rgrpd_cachep;
extern void gfs2_glock_add_to_lru(struct gfs2_glock *gl);
extern void gfs2_glock_put(struct gfs2_glock *gl);
extern void gfs2_free_clones(struct gfs2_rgrpd *rgd);
extern void return_all_reservations(struct gfs2_rgrpd *rgd);
extern void kfree(void *ptr);
extern void kmem_cache_free(struct kmem_cache *cachep, void *objp);