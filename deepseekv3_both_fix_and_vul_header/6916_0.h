#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *input;
    char *inputName;
    void *bs;
    void *display_list;
    void *fonts;
    void *apps;
    void *sounds;
    char *localPath;
} SWFReader;

#define GF_BITSTREAM_READ 0
#define GF_PATH_SEPARATOR '/'
#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
void *gf_bs_from_file(FILE *f, int mode);
void gf_bs_set_eos_callback(void *bs, void (*callback)(void *), void *param);
void *gf_list_new();
char *gf_strdup(const char *str);
void gf_free(void *ptr);
FILE *gf_fopen(const char *filename, const char *mode);
void swf_io_error(void *param);