#include <stddef.h>

typedef struct {
    void* load_op;
} FileFormat;

typedef void GimpProcedure;
typedef void GimpValueArray;
typedef void GimpImage;
typedef void GFile;
typedef int GimpRunMode;
typedef void GError;
typedef void* gpointer;

#define INIT_I18N()
#define gegl_init(a,b)
#define GIMP_PDB_EXECUTION_ERROR 0
#define GIMP_PDB_SUCCESS 0
#define GIMP_VALUES_SET_IMAGE(a,b,c)