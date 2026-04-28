#include <stddef.h>

class GtkTextBuffer;

class GtkWidget {
public:
    GtkTextBuffer* get_text_buffer();
};

class GtkEntry {
public:
    void set_range(int, int);
};

#define GTK_TEXT_BUFFER(obj) (reinterpret_cast<GtkTextBuffer*>(obj))

class Gobby {
public:
    class GotoDialog {
    private:
        GtkWidget* m_current_view;
        GtkEntry* m_entry_line;
    public:
        void on_changed();
    };
};

extern "C" {
    void g_warning(const char* format, ...);
    void g_assert(bool condition);
    int gtk_text_buffer_get_line_count(GtkTextBuffer* buffer);
}