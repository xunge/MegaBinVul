#include <stdbool.h>
#include <cstddef>

struct GtkTextBuffer;
#define GTK_TEXT_BUFFER(obj) ((GtkTextBuffer*)(obj))

struct View {
    GtkTextBuffer* get_text_buffer();
    void* get_active_user();
};

struct Action {
    void set_enabled(bool);
};

struct Actions {
    Action* copy;
    Action* cut;
};

extern void g_warning(const char* message);
extern void g_assert(bool condition);

class Gobby {
public:
    class EditCommands {
    private:
        View* m_current_view;
        Actions m_actions;
    public:
        void on_mark_set();
    };
};

bool gtk_text_buffer_get_has_selection(GtkTextBuffer* buffer);