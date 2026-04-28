#include <stdbool.h>

class AppController {
public:
    bool SupportsLocationBar() const;
};

class Browser {
public:
    bool SupportsLocationBar() const;
    bool is_type_tabbed() const;
    bool is_app() const;
    bool is_trusted_source() const;
    AppController* hosted_app_controller_;
    AppController* bookmark_app_controller_;
};