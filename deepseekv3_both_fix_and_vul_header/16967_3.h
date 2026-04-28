#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int gboolean;
typedef char gchar;
typedef int gint;
typedef void* gpointer;
typedef unsigned int guint;

typedef struct gerb_file_t {
    gchar* filename;
} gerb_file_t;

typedef struct gerbv_HID_Attribute {
    int dummy;
} gerbv_HID_Attribute;

typedef struct gerbv_image_info_t {
    struct gerbv_HID_Attribute* attr_list;
    int n_attr;
} gerbv_image_info_t;

typedef struct gerbv_image_t {
    gerbv_image_info_t* info;
    int layertype;
} gerbv_image_t;

typedef struct gerbv_fileinfo_t {
    gerbv_image_t* image;
    gboolean layer_dirty;
} gerbv_fileinfo_t;

typedef struct gerbv_project_t {
    gerbv_fileinfo_t** file;
    int max_files;
} gerbv_project_t;

enum {
    GERBV_LAYERTYPE_PICKANDPLACE_TOP,
    GERBV_LAYERTYPE_PICKANDPLACE_BOT
};

#define GERB_COMPILE_ERROR(...)
#define dprintf(...)
#define _(x) x
#define FALSE 0
#define TRUE 1

gerb_file_t* gerb_fopen(const gchar* filename);
void gerb_fclose(gerb_file_t* fd);
gboolean gerber_is_rs274x_p(gerb_file_t* fd, gboolean* foundBinary);
gboolean drill_file_p(gerb_file_t* fd, gboolean* foundBinary);
gboolean pick_and_place_check_file_type(gerb_file_t* fd, gboolean* foundBinary);
gboolean gerber_is_rs274d_p(gerb_file_t* fd);
gerbv_image_t* parse_gerb(gerb_file_t* fd, gchar* currentLoadDirectory);
gerbv_image_t* parse_drillfile(gerb_file_t* fd, struct gerbv_HID_Attribute* attr_list, int n_attr, int reload);
void pick_and_place_parse_file_to_images(gerb_file_t* fd, gerbv_image_t** image1, gerbv_image_t** image2);
int gerbv_add_parsed_image_to_project(gerbv_project_t* project, gerbv_image_t* image, const gchar* filename, gchar* displayedName, int idx, int reload);

gchar* g_strdup(const gchar* str);
gchar* g_path_get_dirname(const gchar* filename);
gchar* g_path_get_basename(const gchar* filename);
gchar* g_strconcat(const gchar* first, ...);
gchar* g_strdup_printf(const gchar* format, ...);
void g_free(gpointer mem);
gpointer g_renew(gpointer type, gpointer mem, guint size);
void g_warning(const gchar* format, ...);

#define g_renew(type, mem, size) ((type*)realloc((mem), (size)*sizeof(type)))