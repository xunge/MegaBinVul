#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MagickPathExtent 1024
#define MagickFalse 0
#define MagickTrue 1

typedef int MagickBooleanType;

typedef struct _Image {
    size_t columns;
    size_t rows;
} Image;

typedef struct _ExceptionInfo {
    int dummy;
} ExceptionInfo;

typedef struct _StringInfo {
    size_t length;
    unsigned char *datum;
} StringInfo;

static inline void CopyMagickString(char *dest, const char *src, size_t len) {
    strncpy(dest, src, len);
    dest[len-1] = '\0';
}

static inline void *CopyMagickMemory(void *dest, const void *src, size_t len) {
    return memcpy(dest, src, len);
}

static inline long StringToLong(const char *str) {
    return strtol(str, NULL, 10);
}

static inline ssize_t ReadPropertyByte(const unsigned char **data, size_t *length) {
    if (*length == 0) return -1;
    (*length)--;
    return (ssize_t) *(*data)++;
}

static inline ssize_t ReadPropertyMSBShort(const unsigned char **data, size_t *length) {
    if (*length < 2) return -1;
    *length -= 2;
    return (ssize_t) ((*data)[0] << 8 | (*data)[1]);
}

static inline ssize_t ReadPropertyMSBLong(const unsigned char **data, size_t *length) {
    if (*length < 4) return -1;
    *length -= 4;
    return (ssize_t) ((*data)[0] << 24 | (*data)[1] << 16 | (*data)[2] << 8 | (*data)[3]);
}

static inline ssize_t MagickMax(ssize_t a, ssize_t b) {
    return a > b ? a : b;
}

static inline size_t MagickMin(ssize_t a, ssize_t b) {
    return (size_t)(a < b ? a : b);
}

static inline int LocaleCompare(const char *a, const char *b) {
    return strcmp(a, b);
}

static inline void *AcquireQuantumMemory(size_t count, size_t size) {
    return calloc(count, size);
}

static inline char *DestroyString(char *str) {
    free(str);
    return NULL;
}

static inline const StringInfo *GetImageProfile(const Image *image, const char *name) {
    return NULL;
}

static inline const unsigned char *GetStringInfoDatum(const StringInfo *info) {
    return info ? info->datum : NULL;
}

static inline size_t GetStringInfoLength(const StringInfo *info) {
    return info ? info->length : 0;
}

static inline MagickBooleanType SetImageProperty(Image *image, const char *key, const char *value, ExceptionInfo *exception) {
    return MagickFalse;
}

static inline char *TraceSVGClippath(const unsigned char *data, size_t length, size_t width, size_t height) {
    return NULL;
}

static inline char *TracePSClippath(const unsigned char *data, size_t length) {
    return NULL;
}