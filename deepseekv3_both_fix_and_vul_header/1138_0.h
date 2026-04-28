#include <stdio.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} BMP;

void* jfif_load(const char* filename);
void jfif_decode(void* jfif, BMP* bmp);
void jfif_free(void* jfif);
int bmp_save(BMP* bmp, const char* filename);
void bmp_free(BMP* bmp);
int bmp_load(BMP* bmp, const char* filename);
void* jfif_encode(BMP* bmp);
int jfif_save(void* jfif, const char* filename);