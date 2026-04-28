#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_MAX 4096
#define FALSE 0
#define TRUE 1
typedef int gboolean;

typedef struct _IMAGE IMAGE;

typedef enum {
    VIPS_FOREIGN_DZ_LAYOUT_DZ
} VipsForeignDzLayout;

typedef enum {
    VIPS_FOREIGN_DZ_DEPTH_ONEPIXEL
} VipsForeignDzDepth;

typedef enum {
    VIPS_ANGLE_D0
} VipsAngle;

#define VIPS_TYPE_FOREIGN_DZ_LAYOUT 0
#define VIPS_TYPE_FOREIGN_DZ_DEPTH 0
#define VIPS_TYPE_ANGLE 0

extern int im_strncpy(char *dest, const char *src, int n);
extern char *im_getnextoption(char **p);
extern int vips_enum_from_nick(const char *domain, int type, const char *str);
extern int im_isprefix(const char *a, const char *b);
extern int vips_dzsave(IMAGE *in, const char *name, ...);
extern char *g_strdup(const char *str);