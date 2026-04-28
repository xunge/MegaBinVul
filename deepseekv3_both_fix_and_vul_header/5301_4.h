#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>

typedef uint32_t u32;

#define GF_BAD_PARAM 1

typedef struct GF_XMTParser GF_XMTParser;
typedef struct GF_ObjectDescriptor GF_ObjectDescriptor;
typedef struct XMT_ODLink XMT_ODLink;

struct GF_ObjectDescriptor {
    u32 objectDescriptorID;
};

struct GF_XMTParser {
    void *od_links;
};

struct XMT_ODLink {
    u32 ID;
    GF_ObjectDescriptor *od;
    char *desc_name;
    void *mf_urls;
};

#define GF_SAFEALLOC(ptr, type) (ptr = (type*)calloc(1, sizeof(type)))

static inline int strnicmp(const char *s1, const char *s2, size_t n) {
    return strncasecmp(s1, s2, n);
}

static inline char *gf_strdup(const char *str) {
    return str ? strdup(str) : NULL;
}

static inline void *gf_list_new() {
    return calloc(1, sizeof(struct XMT_ODLink));
}

static inline u32 gf_list_count(void *list) {
    return list ? 0 : 0;
}

static inline void *gf_list_get(void *list, u32 index) {
    return NULL;
}

static inline void gf_list_add(void *list, void *item) {
}

static inline void gf_list_rem(void *list, u32 index) {
}

static inline void gf_list_del(void *list) {
    free(list);
}

static inline void gf_free(void *ptr) {
    free(ptr);
}

static inline void xmt_report(GF_XMTParser *parser, int code, const char *fmt, ...) {
}