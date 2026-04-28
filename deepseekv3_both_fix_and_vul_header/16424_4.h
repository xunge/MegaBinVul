#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct InfAdoptedUser;
#define INF_ADOPTED_USER(obj) ((InfAdoptedUser*)(obj))

namespace Gobby {
    struct EditCommands {
        struct View {
            InfAdoptedUser* get_active_user();
        };
        
        struct {
            struct {
                void set_enabled(bool);
            } *undo;
        } m_actions;
        
        View* m_current_view;
        
        void on_can_undo_changed(InfAdoptedUser* user, bool can_undo);
    };
}

#define g_warning(msg) fprintf(stderr, "Warning: %s\n", msg)
#define g_assert(expr) do { if (!(expr)) { fprintf(stderr, "Assertion failed: %s\n", #expr); abort(); } } while (0)