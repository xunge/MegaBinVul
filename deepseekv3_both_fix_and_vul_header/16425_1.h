#include <stddef.h>

struct GtkTextBuffer;
struct _GtkClipboard;
#define GDK_SELECTION_CLIPBOARD 0
#define GTK_TEXT_BUFFER(x) ((GtkTextBuffer*)(x))
#define TRUE 1

struct Gobby {
    struct EditCommands {
        void on_paste();
        class View {
        public:
            void* get_active_user();
            void* get_text_buffer();
            void scroll_to_cursor_position(double);
        };
        View* m_current_view;
    };
};

void g_warning(const char* message);
void g_assert(int expression);
void gtk_text_buffer_paste_clipboard(GtkTextBuffer* buffer, _GtkClipboard* clipboard, void* unused, int default_editable);
_GtkClipboard* gtk_clipboard_get(int selection);