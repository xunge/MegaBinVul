#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef int Bool;
typedef int GF_Err;
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

#define GF_OK 0
#define GF_CORRUPTED_DATA 1
#define VOBSUBIDXVER 7
#define LLX "%llx"

typedef struct {
    u16 id;
    const char *name;
    s32 idx;
    void *subpos;
} vobsub_lang;

typedef struct {
    s64 start;
    u64 filepos;
} vobsub_pos;

typedef struct {
    s32 width;
    s32 height;
    u8 palette[16][4];
    vobsub_lang langs[32];
    s32 num_langs;
} vobsub_file;

typedef struct {
    const char *lang;
    u16 id;
} lang_table_entry;

extern const lang_table_entry lang_table[];

char *gf_fgets(char *s, int size, FILE *stream);
char *strtrim(char *str);
int stricmp(const char *s1, const char *s2);
char *strlwr(char *str);
void *gf_calloc(size_t nmemb, size_t size);
void gf_free(void *ptr);
void *gf_list_new(void);
int gf_list_add(void *list, void *item);
int gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
u16 vobsub_lang_name(u16 id);