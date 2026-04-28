#include <stdlib.h>
#include <string.h>

typedef unsigned char stbi_uc;

typedef struct
{
   // stbi__context members would be defined here
} stbi__context;

typedef struct
{
   // stbi__result_info members would be defined here
} stbi__result_info;

#define STBI_NOTUSED(x) (void)(x)
#define STBI_MAX_DIMENSIONS (1 << 24)
#define STBI_FREE(p) free(p)

static void *stbi__errpuc(const char *str1, const char *str2);
static int stbi__get8(stbi__context *s);
static unsigned int stbi__get16be(stbi__context *s);
static unsigned int stbi__get32be(stbi__context *s);
static int stbi__at_eof(stbi__context *s);
static int stbi__mad3sizes_valid(int a, int b, int c, int add);
static void *stbi__malloc_mad3(int a, int b, int c, int add);
static int stbi__pic_load_core(stbi__context *s, int x, int y, int *comp, stbi_uc *result);
static void *stbi__convert_format(void *data, int orig_comp, int req_comp, int x, int y);