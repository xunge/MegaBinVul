#include <cstddef>

struct GtkTextIter {};

namespace Gtk {
    enum ResponseType {
        RESPONSE_ACCEPT,
        RESPONSE_CLOSE
    };
    class Dialog {
    public:
        void on_response(int id);
    };
}

namespace Gobby {
    class GotoDialog : public Gtk::Dialog {
    public:
        void on_response(int id);
    private:
        class View {
        public:
            void* get_text_buffer();
            void set_selection(GtkTextIter* start, GtkTextIter* end);
        };
        View* m_current_view;
        class Entry {
        public:
            int get_value_as_int();
        };
        Entry* m_entry_line;
        void hide();
    };
}

typedef void* GtkTextBuffer;
void gtk_text_buffer_get_iter_at_line(GtkTextBuffer* buffer, GtkTextIter* iter, int line_number);
void g_warning(const char* message);
void g_assert(bool condition);
#define GTK_TEXT_BUFFER(buffer) (reinterpret_cast<GtkTextBuffer*>(buffer))