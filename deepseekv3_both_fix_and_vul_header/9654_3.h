#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _GValueArray GValueArray;
typedef struct _GValue GValue;
typedef struct _GtkWidget GtkWidget;
typedef struct _GdkScreen GdkScreen;
typedef struct _GtkAllocation GtkAllocation;

struct _GValueArray {
    uint32_t n_values;
    GValue *values;
};

struct _GValue {
    long data;
};

struct _GtkAllocation {
    int width;
    int height;
};

typedef struct _VteTerminal VteTerminal;
typedef struct _VteScreen VteScreen;
typedef struct _VteTerminalPrivate VteTerminalPrivate;

struct _GtkWidget {
    /* Minimal widget definition */
    int mapped;
    void* window;
    GdkScreen* screen;
};

struct _VteTerminal {
    struct _GtkWidget widget;
    VteTerminalPrivate *pvt;
    long row_count;
    long column_count;
    int char_width;
    int char_height;
    char *icon_title;
    char *window_title;
};

struct _VteTerminalPrivate {
    VteScreen *screen;
    struct {
        int left;
        int right;
        int top;
        int bottom;
    } inner_border;
};

struct _VteScreen {
    /* Placeholder */
};

#define VTE_DEBUG_PARSE 0
#define _VTE_CAP_CSI "\033["
#define _VTE_CAP_OSC "\033]"
#define _VTE_CAP_ST "\033\\"

#define G_VALUE_HOLDS_LONG(value) (1)
#define g_value_get_long(value) ((value)->data)
#define gint int
#define guint uint32_t
#define g_snprintf snprintf

GValue* g_value_array_get_nth(GValueArray *array, uint32_t index);
int gtk_widget_get_mapped(GtkWidget *widget);
void gdk_window_get_origin(void *window, int *x, int *y);
void* gtk_widget_get_window(GtkWidget *widget);
void gtk_widget_get_allocation(GtkWidget *widget, GtkAllocation *allocation);
GdkScreen* gtk_widget_get_screen(GtkWidget *widget);
int gdk_screen_get_height(GdkScreen *screen);
int gdk_screen_get_width(GdkScreen *screen);

void _vte_debug_print(int debug, const char *format, ...);
void _vte_invalidate_all(VteTerminal *terminal);
void vte_terminal_emit_deiconify_window(VteTerminal *terminal);
void vte_terminal_emit_iconify_window(VteTerminal *terminal);
void vte_terminal_emit_move_window(VteTerminal *terminal, long x, long y);
void vte_terminal_emit_resize_window(VteTerminal *terminal, int width, int height);
void vte_terminal_emit_raise_window(VteTerminal *terminal);
void vte_terminal_emit_lower_window(VteTerminal *terminal);
void vte_terminal_emit_refresh_window(VteTerminal *terminal);
void vte_terminal_emit_restore_window(VteTerminal *terminal);
void vte_terminal_emit_maximize_window(VteTerminal *terminal);
void vte_terminal_feed_child(VteTerminal *terminal, const char *data, long length);