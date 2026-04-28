#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char *name;
    int is_alt;
} bntann1_t;

typedef struct {
    int n_seqs;
    bntann1_t *anns;
} bntseq_t;

typedef uint32_t khint32_t;
typedef struct kh_str_t {
    khint32_t *flags;
    const char **keys;
    int *vals;
    khint32_t n_buckets, size, n_occupied, upper_bound;
} kh_str_t;

typedef unsigned int khint_t;

#define khash_t(name) kh_##name##_t
#define kh_init(name) kh_init_##name()
#define kh_destroy(name, h) kh_destroy_##name(h)
#define kh_put(name, h, k, r) kh_put_##name(h, k, r)
#define kh_get(name, h, k) kh_get_##name(h, k)
#define kh_val(h, k) ((h)->vals[k])
#define kh_end(h) ((h)->n_buckets)

extern bntseq_t *bns_restore_core(const char *ann_filename, const char *amb_filename, const char *pac_filename);
extern kh_str_t *kh_init_str(void);
extern void kh_destroy_str(kh_str_t *h);
extern khint_t kh_put_str(kh_str_t *h, const char *key, int *ret);
extern khint_t kh_get_str(const kh_str_t *h, const char *key);