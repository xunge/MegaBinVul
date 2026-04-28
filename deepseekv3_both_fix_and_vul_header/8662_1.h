#include <string.h>
#include <stdlib.h>

typedef int gboolean;
typedef struct _GsfInfileTar GsfInfileTar;
typedef struct _GsfInput GsfInput;
typedef struct _GsfInfile GsfInfile;

#define GSF_INFILE(obj) ((GsfInfile *)(obj))
#define GSF_INFILE_TAR(obj) ((GsfInfileTar *)(obj))

char *g_strndup(const char *str, size_t n);
void g_free(void *ptr);
void g_object_unref(void *obj);
GsfInput *gsf_infile_child_by_name(GsfInfile *infile, const char *name);
GsfInfileTar *tar_create_dir(GsfInfileTar *dir, const char *name);