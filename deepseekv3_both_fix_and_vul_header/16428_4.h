#include <stddef.h>

typedef unsigned long gulong;

struct GtkTextBuffer;
struct GtkTextIter {
    void* dummy[12];
};
struct GtkTextMark;
struct InfAdoptedSession;
struct InfAdoptedUser;
struct UndoGrouping {
    int get_redo_size();
};

#define G_CALLBACK(f) ((void (*)(void))f)
#define GTK_TEXT_BUFFER(obj) ((GtkTextBuffer*)obj)
#define INF_ADOPTED_SESSION(obj) ((InfAdoptedSession*)obj)
#define INF_ADOPTED_USER(obj) ((InfAdoptedUser*)obj)

namespace Gobby {
    class View {
    public:
        GtkTextBuffer* get_text_buffer();
        InfAdoptedSession* get_session();
        InfAdoptedUser* get_active_user();
        UndoGrouping get_undo_grouping();
        void scroll_to_cursor_position(double);
    };

    class EditCommands {
    public:
        void on_redo();
    private:
        View* m_current_view;
    };
}

extern GtkTextMark* check;
extern void recaret_i();
extern void recaret_e();
extern void g_warning(const char*);
extern int g_assert(int);
extern gulong g_signal_connect_after(void*, const char*, void (*)(void), void*);
extern void g_signal_handler_disconnect(void*, gulong);
extern void inf_adopted_session_redo(InfAdoptedSession*, InfAdoptedUser*, int);
extern void gtk_text_buffer_get_iter_at_mark(GtkTextBuffer*, GtkTextIter*, GtkTextMark*);
extern void gtk_text_buffer_select_range(GtkTextBuffer*, GtkTextIter*, GtkTextIter*);
extern void gtk_text_buffer_delete_mark(GtkTextBuffer*, GtkTextMark*);