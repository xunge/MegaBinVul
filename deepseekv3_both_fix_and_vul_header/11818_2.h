#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct FT_FaceRec_* FT_Face;
typedef int FT_Error;
typedef long FT_Fixed;
typedef unsigned long FT_ULong;

typedef struct {
    FT_Fixed *coords;
    char *name;
} FT_Var_Named_Style;

typedef struct {
    unsigned int num_axis;
    unsigned int num_namedstyles;
    struct {
        FT_ULong tag;
        FT_Fixed def;
    } *axis;
    FT_Var_Named_Style *namedstyle;
} FT_MM_Var;

typedef struct _cairo_ft_unscaled_font cairo_ft_unscaled_font_t;
typedef struct _cairo_ft_scaled_font cairo_ft_scaled_font_t;

struct _cairo_ft_unscaled_font {
    unsigned int id;
    FT_Fixed *variations;
};

struct _cairo_ft_scaled_font {
    cairo_ft_unscaled_font_t *unscaled;
    struct {
        struct {
            const char *variations;
        } base;
    } ft_options;
};

#define FT_MAKE_TAG(a, b, c, d) ((FT_ULong)(((a) << 24) | ((b) << 16) | ((c) << 8) | (d)))

static int FT_Get_MM_Var(FT_Face face, FT_MM_Var **amaster);
static int FT_Set_Var_Design_Coordinates(FT_Face face, unsigned int num_coords, FT_Fixed *coords);
static int FT_Get_Var_Design_Coordinates(FT_Face face, unsigned int num_coords, FT_Fixed *coords);

static int _cairo_isspace(char c) { return isspace(c); }
static double _cairo_strtod(const char *nptr, char **endptr) { return strtod(nptr, endptr); }