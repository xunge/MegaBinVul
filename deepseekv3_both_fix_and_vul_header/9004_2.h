#include <stdlib.h>
#include <string.h>

#define CD_FLAG_TXT (1 << 0)

typedef void* GtkTreeView;
typedef void* GtkTreePath; 
typedef void* GtkTreeViewColumn;
typedef void* gpointer;
typedef void* GtkWidget;
typedef void* GtkWindow;
typedef void* GtkBox;
typedef void* GtkScrolledWindow;
typedef void* GtkTextView;
typedef void* GtkDialog;

struct problem_item {
    int flags;
    char *content;
};

typedef int gboolean;
typedef char gchar;
typedef int gint;

#define FALSE 0
#define TRUE 1
#define EXIT_SUCCESS 0
#define G_SPAWN_SEARCH_PATH (1 << 0)
#define G_SPAWN_STDOUT_TO_DEV_NULL (1 << 1)
#define GTK_RESPONSE_OK 1
#define GTK_RESPONSE_CANCEL 2
#define GTK_DIALOG_MODAL (1 << 0)
#define GTK_DIALOG_DESTROY_WITH_PARENT (1 << 1)

extern struct problem_item *get_current_problem_item_or_NULL(GtkTreeView *tree_view, gchar **item_name);
extern char *concat_path_file(const char *dir, const char *file);
extern void load_text_to_text_view(GtkTextView *textview, const gchar *item_name);
extern void save_text_from_text_view(GtkTextView *textview, const gchar *item_name);
extern const char *g_dump_dir_name;
extern GtkWindow *g_wnd_assistant;

extern gboolean g_spawn_sync(void*, char**, void*, int, void*, void*, void*, void*, gint*, void*);
extern void g_free(void*);