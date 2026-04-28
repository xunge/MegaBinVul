#include <cstddef>

namespace Gobby {
    class EditCommands {
    public:
        void on_copy();
    };
}

struct GtkTextBuffer;
struct GtkClipboard;

#define GTK_TEXT_BUFFER(obj) ((GtkTextBuffer*)(obj))
#define GDK_SELECTION_CLIPBOARD 0

struct View {
    void* get_text_buffer();
};

extern View* m_current_view;

void g_warning(const char* message);
void g_assert(bool condition);
GtkClipboard* gtk_clipboard_get(int selection);
void gtk_text_buffer_copy_clipboard(GtkTextBuffer* buffer, GtkClipboard* clipboard);