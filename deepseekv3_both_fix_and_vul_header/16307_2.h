#include <stddef.h>
#include <stdbool.h>

#define PAGE_SHIFT 12
#define GFP_KERNEL 0
#define __GFP_NORETRY 0
#define __GFP_NOWARN 0
#define EAGAIN 11

struct page;
struct mm_struct;
struct sg_table;

struct task_struct {
    struct mm_struct *mm;
};

extern struct task_struct *current;

struct drm_i915_gem_object {
    struct {
        size_t size;
    } base;
    struct {
        struct {
            struct mm_struct *mm;
        } *mm;
        unsigned long ptr;
        void *work;
    } userptr;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-4096)
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))
#define PTR_ERR_OR_ZERO(x) (IS_ERR(x) ? PTR_ERR(x) : 0)

static inline bool i915_gem_object_is_readonly(struct drm_i915_gem_object *obj) { return false; }
static struct sg_table *__i915_gem_userptr_get_pages_schedule(struct drm_i915_gem_object *obj) { return NULL; }
static struct sg_table *__i915_gem_userptr_alloc_pages(struct drm_i915_gem_object *obj, struct page **pvec, unsigned long num_pages) { return NULL; }
static void __i915_gem_userptr_set_active(struct drm_i915_gem_object *obj, bool active) {}
static int __get_user_pages_fast(unsigned long start, int nr_pages, int write, struct page **pages) { return 0; }
static void release_pages(struct page **pages, int nr_pages) {}
static void *kvmalloc_array(size_t n, size_t size, int flags) { return NULL; }
static void kvfree(const void *addr) {}