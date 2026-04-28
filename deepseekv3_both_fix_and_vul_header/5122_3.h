#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
typedef struct GF_ISOFile GF_ISOFile;
typedef unsigned int u32;
typedef double Double;
typedef unsigned char Bool;

#define GF_LOG_ERROR 0
#define GF_LOG_CONTAINER 0
#define GF_NOT_SUPPORTED 0
#define GF_PATH_SEPARATOR '/'

struct CATEnum {
    GF_ISOFile *dest;
    u32 import_flags;
    Double force_fps;
    u32 frames_per_sample;
    char *tmp_dir;
    Bool force_cat;
    Bool align_timelines;
    Bool allow_add_in_command;
    char szPath[1024];
    char szRad1[1024];
    char szRad2[1024];
    char szOpt[1024];
};

typedef struct CATEnum CATEnum;

void GF_LOG(int level, int category, const char *fmt, ...);
GF_Err gf_enum_directory(const char *path, int arg1, void (*callback)(void*, char*, char*), CATEnum *cat_enum, void *arg2);
void cat_enumerate(void *param, char *item_name, char *item_path);