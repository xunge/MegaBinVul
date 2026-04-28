#include <stddef.h>

struct InfTextSession;
struct InfAdoptedAlgorithm;
struct InfAdoptedSession;

struct CurrentView {
    InfTextSession* get_session();
};

#define INF_ADOPTED_SESSION(session) ((InfAdoptedSession*)(session))
#define G_OBJECT(obj) ((void*)(obj))
#define G_CALLBACK(func) ((void*)(func))

namespace Gobby {
    class EditCommands {
    public:
        CurrentView* m_current_view;
        unsigned long m_can_undo_changed_handler;
        unsigned long m_can_redo_changed_handler;
        unsigned long m_synchronization_complete_handler;

        static void on_can_undo_changed_static();
        static void on_can_redo_changed_static();
        
        void on_sync_complete();
    };
}

void g_warning(const char* message);
void g_assert(int expression);
unsigned long g_signal_connect(void* instance, const char* signal, void* callback, void* data);
void g_signal_handler_disconnect(void* instance, unsigned long handler_id);
InfAdoptedAlgorithm* inf_adopted_session_get_algorithm(InfAdoptedSession* session);