#include <stdlib.h>
#include <string.h>

#define STBI__HDR_BUFLEN 1024
#define STBI_MAX_DIMENSIONS (1 << 24)
#define STBI_NOTUSED(x) (void)(x)
#define STBI_FREE(p) free(p)

typedef struct {
    // stbi__context fields would be defined here
} stbi__context;

typedef struct {
    // stbi__result_info fields would be defined here
} stbi__result_info;

typedef unsigned char stbi_uc;

static char *stbi__hdr_gettoken(stbi__context *z, char *buffer);
static float *stbi__errpf(const char *reason, const char *msg);
static int stbi__mad4sizes_valid(int a, int b, int c, int d, int add);
static void *stbi__malloc_mad4(int a, int b, int c, int d, int add);
static void stbi__hdr_convert(float *output, stbi_uc *input, int req_comp);
static int stbi__get8(stbi__context *s);
static void stbi__getn(stbi__context *s, stbi_uc *buffer, int n);
static void *stbi__malloc_mad2(int a, int b, int add);