#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned int u32;

typedef struct {
    u32 OD_ID;
} MFURLValue;

typedef struct {
    MFURLValue *vals;
    u32 count;
} MFURL;

typedef struct {
    u32 objectDescriptorID;
} GF_ObjectDescriptor;

typedef struct XMT_ODLink {
    char *desc_name;
    GF_ObjectDescriptor *od;
    u32 ID;
    struct GF_List *mf_urls;
} XMT_ODLink;

typedef struct GF_List GF_List;

typedef struct GF_XMTParser {
    GF_List *od_links;
} GF_XMTParser;

struct GF_List {
    // Minimal definition for compilation
};

GF_List *gf_list_new(void);
void gf_list_add(GF_List *list, void *item);
int gf_list_find(GF_List *list, void *item);
void *gf_list_enum(GF_List *list, u32 *pos);
#define GF_SAFEALLOC(ptr, type) ((ptr) = (type*)malloc(sizeof(type)))
char *gf_strdup(const char *str);
int strnicmp(const char *s1, const char *s2, size_t n);