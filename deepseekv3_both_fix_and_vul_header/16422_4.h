#include <string>
#include <cassert>

namespace Glib {
    using ustring = std::string;
}

namespace Gobby {
    class ViewCommands {
    public:
        void on_menu_language_changed();
    private:
        struct ActionGroup {
            struct HighlightMode {
                void get_state(Glib::ustring&);
            } *highlight_mode;
        } m_actions;
        
        void* m_language_manager;
        struct SourceView {
            void set_language(void*);
        } *m_current_view;
        
        struct Connection {
            void block();
            void unblock();
        } m_document_language_changed_connection;
    };
}

using GtkSourceLanguage = void;
#define gtk_source_language_manager_get_language(manager, id) (nullptr)
#define g_assert(expr) assert(expr)
#define g_warning(msg) ((void)0)