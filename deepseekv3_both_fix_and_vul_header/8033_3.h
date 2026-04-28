#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define GIMP_MESSAGE_WARNING 1

typedef bool gboolean;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned char guchar;
typedef long glong;

typedef enum {
  PROP_END,
  PROP_ACTIVE_CHANNEL,
  PROP_SELECTION,
  PROP_OPACITY,
  PROP_VISIBLE,
  PROP_LINKED,
  PROP_LOCK_CONTENT,
  PROP_SHOW_MASKED,
  PROP_COLOR,
  PROP_TATTOO,
  PROP_PARASITES
} PropType;

typedef struct {
  guint8 r, g, b;
} GimpRGB;

typedef struct _XcfInfo {
  FILE *fp;
  long cp;
  void *gimp;
  void *progress;
  void *active_channel;
} XcfInfo;

typedef struct _GimpImage GimpImage;
typedef struct _GimpChannel GimpChannel;
typedef struct _GimpItem GimpItem;
typedef struct _GimpDrawable {
  struct {
    void *tiles;
  } *private;
} GimpDrawable;
typedef struct _GimpParasite GimpParasite;
typedef uint32_t GimpTattoo;
typedef void TileManager;

#define GIMP_ITEM(item) ((GimpItem*)(item))
#define GIMP_DRAWABLE(drawable) ((GimpDrawable*)(drawable))
#define G_OBJECT(obj) ((void*)(obj))

gboolean xcf_load_prop(XcfInfo *info, PropType *prop_type, guint32 *prop_size);
int32_t xcf_read_int32(FILE *fp, guint32 *data, int count);
int32_t xcf_read_int8(FILE *fp, guint8 *data, int count);
GimpChannel *gimp_selection_new(GimpImage *image, int width, int height);
void gimp_image_take_mask(GimpImage *image, GimpChannel *mask);
void tile_manager_unref(TileManager *manager);
void g_object_unref(void *object);
void gimp_channel_set_opacity(GimpChannel *channel, double opacity, gboolean push_undo);
void gimp_item_set_visible(GimpItem *item, gboolean visible, gboolean push_undo);
void gimp_item_set_linked(GimpItem *item, gboolean linked, gboolean push_undo);
void gimp_item_set_lock_content(GimpItem *item, gboolean lock_content, gboolean push_undo);
void gimp_channel_set_show_masked(GimpChannel *channel, gboolean show_masked);
void gimp_rgb_set_uchar(GimpRGB *rgb, guint8 r, guint8 g, guint8 b);
void gimp_item_set_tattoo(GimpItem *item, GimpTattoo tattoo);
GimpParasite *xcf_load_parasite(XcfInfo *info);
void gimp_item_parasite_attach(GimpItem *item, GimpParasite *parasite, gboolean push_undo);
void gimp_parasite_free(GimpParasite *parasite);
void gimp_message_literal(void *gimp, void *progress, int type, const char *message);
gboolean xcf_skip_unknown_prop(XcfInfo *info, guint32 prop_size);
int gimp_item_get_width(GimpItem *item);
int gimp_item_get_height(GimpItem *item);

struct _GimpChannel {
  GimpItem *parent_instance;
  gboolean boundary_known;
  gboolean bounds_known;
  GimpRGB color;
  GimpDrawable *private;
};