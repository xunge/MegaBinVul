#include <stdlib.h>
#include <string.h>

typedef int gboolean;
typedef int gint;
typedef double gdouble;

typedef struct {
    gint n_dash;
    gdouble *dash;
    gdouble offset;
} RsvgDash;

typedef struct {
    gboolean has_current_color;
    gboolean has_flood_color;
    gboolean has_flood_opacity;
    gboolean has_fill_server;
    gboolean has_fill_opacity;
    gboolean has_fill_rule;
    gboolean has_clip_rule;
    gboolean has_stroke_server;
    gboolean has_stroke_opacity;
    gboolean has_stroke_width;
    gboolean has_miter_limit;
    gboolean has_cap;
    gboolean has_join;
    gboolean has_stop_color;
    gboolean has_stop_opacity;
    gboolean has_cond;
    gboolean has_font_size;
    gboolean has_font_style;
    gboolean has_font_variant;
    gboolean has_font_weight;
    gboolean has_font_stretch;
    gboolean has_font_decor;
    gboolean has_text_dir;
    gboolean has_text_gravity;
    gboolean has_unicode_bidi;
    gboolean has_text_anchor;
    gboolean has_letter_spacing;
    gboolean has_startMarker;
    gboolean has_middleMarker;
    gboolean has_endMarker;
    gboolean has_shape_rendering_type;
    gboolean has_text_rendering_type;
    gboolean has_font_family;
    gboolean has_space_preserve;
    gboolean has_visible;
    gboolean has_lang;
    gboolean has_dash;
    gboolean has_dashoffset;
    
    void *current_color;
    void *flood_color;
    gdouble flood_opacity;
    void *fill;
    gdouble fill_opacity;
    int fill_rule;
    int clip_rule;
    int overflow;
    void *stroke;
    gdouble stroke_opacity;
    gdouble stroke_width;
    gdouble miter_limit;
    int cap;
    int join;
    void *stop_color;
    gdouble stop_opacity;
    gboolean cond_true;
    gdouble font_size;
    int font_style;
    int font_variant;
    int font_weight;
    int font_stretch;
    int font_decor;
    int text_dir;
    int text_gravity;
    int unicode_bidi;
    int text_anchor;
    gdouble letter_spacing;
    void *startMarker;
    void *middleMarker;
    void *endMarker;
    int shape_rendering_type;
    int text_rendering_type;
    char *font_family;
    gboolean space_preserve;
    gboolean visible;
    char *lang;
    RsvgDash dash;
    
    void *clip_path_ref;
    void *mask;
    void *enable_background;
    void *adobe_blend;
    gdouble opacity;
    void *filter;
    void *comp_op;
} RsvgState;

typedef gboolean (*InheritanceFunction)(gboolean, gboolean);

void rsvg_paint_server_ref(void *server);
void rsvg_paint_server_unref(void *server);
char *g_strdup(const char *str);
void g_free(void *ptr);
void *g_new(size_t size, size_t count);

#define g_new(type, count) ((type*)malloc(sizeof(type) * (count)))