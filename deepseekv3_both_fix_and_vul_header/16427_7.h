#include <assert.h>
#include <stddef.h>

#define g_assert assert

typedef unsigned long gulong;

struct GtkTextBuffer;
struct GtkTextIter {
    void* dummy1;
    void* dummy2;
    void* dummy3;
    void* dummy4;
};
struct GtkTextMark;
struct InfAdoptedSession;
struct InfAdoptedUser;

struct UndoGrouping {
    int get_undo_size();
};

struct View {
    GtkTextBuffer* get_text_buffer();
    InfAdoptedSession* get_session();
    InfAdoptedUser* get_active_user();
    UndoGrouping get_undo_grouping();
    void scroll_to_cursor_position(double);
};

struct Gobby {
    struct EditCommands {
        View* m_current_view;
        void on_undo();
    };
};

extern GtkTextMark* check;
extern void recaret_i();
extern void recaret_e();
extern void g_warning(const char* message);
extern gulong g_signal_connect_after(void* instance, const char* signal, void* handler, void* data);
extern void g_signal_handler_disconnect(void* instance, gulong handler_id);
extern void inf_adopted_session_undo(InfAdoptedSession* session, InfAdoptedUser* user, int undo_size);
extern void gtk_text_buffer_get_iter_at_mark(GtkTextBuffer* buffer, GtkTextIter* iter, GtkTextMark* mark);
extern void gtk_text_buffer_select_range(GtkTextBuffer* buffer, const GtkTextIter* start, const GtkTextIter* end);
extern void gtk_text_buffer_delete_mark(GtkTextBuffer* buffer, GtkTextMark* mark);

#define G_CALLBACK(f) ((void*)(f))
#define GTK_TEXT_BUFFER(buffer) ((GtkTextBuffer*)(buffer))
#define INF_ADOPTED_SESSION(session) ((InfAdoptedSession*)(session))
#define INF_ADOPTED_USER(user) ((InfAdoptedUser*)(user))