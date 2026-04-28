#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define GDK_SELECTION_CLIPBOARD 0
#define GTK_TEXT_BUFFER(x) ((GtkTextBuffer*)(x))

typedef struct _GtkTextBuffer GtkTextBuffer;

void g_warning(const char*);
void g_assert(int);
void* gtk_clipboard_get(int);
void gtk_text_buffer_cut_clipboard(GtkTextBuffer*, void*, int);

class Gobby {
public:
    class EditCommands {
    public:
        void on_cut();
    private:
        class View* m_current_view;
    };
};

class View {
public:
    void* get_active_user();
    GtkTextBuffer* get_text_buffer();
    void scroll_to_cursor_position(double);
};