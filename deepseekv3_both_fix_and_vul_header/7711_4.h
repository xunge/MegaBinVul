#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef char gchar;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef float gfloat;
typedef int gint;

typedef struct _GList GList;
struct _GList {
    void *data;
    GList *next;
};

typedef struct _XcfInfo {
    GList *linked_paths;
} XcfInfo;

typedef struct _GimpImage GimpImage;
typedef struct _GimpVectors GimpVectors;
typedef struct _GimpItem GimpItem;
typedef struct _GimpContainer GimpContainer;

typedef uint32_t GimpTattoo;

typedef struct {
    gint32 type;
    gfloat x;
    gfloat y;
} GimpVectorsCompatPoint;

#define GIMP_ITEM(obj) ((GimpItem*)(obj))
#define g_new0(type, count) ((type*)calloc(count, sizeof(type)))

GList* g_list_prepend(GList *list, void *data);
void g_free(void *mem);
void g_printerr(const char *format, ...);

GimpVectors* gimp_vectors_compat_new(GimpImage *image, const gchar *name,
                                    GimpVectorsCompatPoint *points,
                                    guint32 num_points, guint32 closed);
void gimp_item_set_tattoo(GimpItem *item, GimpTattoo tattoo);
void gimp_image_add_vectors(GimpImage *image, GimpVectors *vectors,
                           void *parent, gint position, gboolean push_undo);
GimpContainer* gimp_image_get_vectors(GimpImage *image);
guint32 gimp_container_get_n_children(GimpContainer *container);

void xcf_read_string(XcfInfo *info, gchar **str, gint count);
void xcf_read_int32(XcfInfo *info, guint32 *val, gint count);
void xcf_read_int8(XcfInfo *info, guint8 *val, gint count);
void xcf_read_float(XcfInfo *info, gfloat *val, gint count);