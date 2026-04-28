#include <cstddef>
#include <cassert>

struct InfUser;
struct InfTextSession;
struct InfAdoptedAlgorithm;
struct GtkTextBuffer;

namespace Gobby {
    class EditCommands {
    public:
        void on_active_user_changed(InfUser* active_user);
    private:
        struct {
            struct {
                void set_enabled(bool);
            } *undo, *redo, *cut, *paste;
        } m_actions;
        struct {
            InfTextSession* get_session();
            GtkTextBuffer* get_text_buffer();
        } *m_current_view;
    };
}

#define INF_ADOPTED_SESSION(session) ((InfAdoptedAlgorithm*)(session))
#define INF_ADOPTED_USER(user) ((InfUser*)(user))
#define GTK_TEXT_BUFFER(buffer) ((GtkTextBuffer*)(buffer))

static inline InfAdoptedAlgorithm* inf_adopted_session_get_algorithm(InfAdoptedAlgorithm* s) { return s; }
static inline bool inf_adopted_algorithm_can_undo(InfAdoptedAlgorithm*, InfUser*) { return false; }
static inline bool inf_adopted_algorithm_can_redo(InfAdoptedAlgorithm*, InfUser*) { return false; }
static inline bool gtk_text_buffer_get_has_selection(GtkTextBuffer*) { return false; }
#define g_assert(expr) assert(expr)
#define g_warning(msg) ((void)0)