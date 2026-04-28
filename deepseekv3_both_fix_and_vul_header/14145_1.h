#include <stdlib.h>
#include <stddef.h>

typedef unsigned char stbi_uc;
typedef unsigned short stbi__uint16;

typedef struct
{
   int img_x, img_y, img_n;
} stbi__context;

typedef struct
{
   int bits_per_channel;
} stbi__result_info;

#define STBI_NOTUSED(x) (void)(x)
#define STBI_MAX_DIMENSIONS (1 << 24)
#define STBI_FREE(p) free(p)

static int stbi__pnm_info(stbi__context *s, int *x, int *y, int *comp);
static void *stbi__errpuc(const char *a, const char *b);
static int stbi__mad4sizes_valid(int a, int b, int c, int d, int add);
static void *stbi__malloc_mad4(int a, int b, int c, int d, int add);
static int stbi__getn(stbi__context *s, stbi_uc *buffer, int n);
static stbi_uc *stbi__convert_format16(stbi__uint16 *data, int img_n, int req_comp, int x, int y);
static stbi_uc *stbi__convert_format(stbi_uc *data, int img_n, int req_comp, int x, int y);