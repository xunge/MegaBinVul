#include <vector>
#include <string>

class UserScript {
public:
    enum RunLocation {
        DOCUMENT_START,
        DOCUMENT_END,
        DOCUMENT_IDLE
    };

    RunLocation run_location() const;
    const std::vector<std::string>& js_scripts() const;
};

class UserScriptInjector {
private:
    const UserScript* script_;
public:
    bool ShouldInjectJs(UserScript::RunLocation run_location) const;
};