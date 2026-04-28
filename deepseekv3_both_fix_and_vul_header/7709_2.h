#include <stdint.h>
#include <stdbool.h>

typedef struct _XcfInfo XcfInfo;
typedef struct _GimpImage GimpImage;
typedef struct _GimpVectors GimpVectors;
typedef struct _GimpContainer GimpContainer;

typedef bool gboolean;
typedef uint32_t guint32;

#define FALSE false
#define TRUE true
#define GIMP_VECTORS(obj) ((GimpVectors*)(obj))
#define GIMP_LOG(domain, format, ...) 

GimpContainer* gimp_image_get_vectors(GimpImage *image);
void* gimp_container_get_child_by_index(GimpContainer *container, guint32 index);
void gimp_image_set_active_vectors(GimpImage *image, GimpVectors *vectors);

void xcf_read_int32(XcfInfo *info, guint32 *value, int count);
gboolean xcf_load_old_path(XcfInfo *info, GimpImage *image);