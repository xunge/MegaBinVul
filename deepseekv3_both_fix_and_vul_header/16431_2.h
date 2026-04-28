#include <cassert>
#include <iostream>

struct InfAdoptedUser;

struct View {
    InfAdoptedUser* get_active_user();
};

struct Action {
    void set_enabled(bool);
};

struct Gobby {
    struct EditCommands {
        struct {
            Action* redo;
        } m_actions;
        View* m_current_view;
        void on_can_redo_changed(InfAdoptedUser*, bool);
    };
};

#define INF_ADOPTED_USER(user) (user)
#define g_warning(msg) std::cerr << "Warning: " << msg << std::endl
#define g_assert(expr) assert(expr)