#include <stddef.h>

typedef short ResID;
typedef unsigned char Str255[256];

typedef struct FamRec_ {
    int ffStylOff;
} FamRec;

typedef struct AsscEntry_ {
    short fontSize;
    short fontID;
} AsscEntry;

typedef struct StyleTable_ {
    short indexes[48];
} StyleTable;

#define EndianS16_BtoN(x) (x)
#define EndianS32_BtoN(x) (x)
#define FT_MIN(a, b) ((a) < (b) ? (a) : (b))

static void ft_memcpy(void* dest, const void* src, size_t n);
static int count_faces_sfnt(char* fond_data);
static void create_lwfn_name(char* ps_name, Str255 lwfn_file_name);