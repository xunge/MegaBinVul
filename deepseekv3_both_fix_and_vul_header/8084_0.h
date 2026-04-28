#include <vector>
#include <string>

class UserScript {
public:
    enum RunLocation {
        DOCUMENT_START
    };

    const std::vector<std::string>& css_scripts() const;
};

class UserScriptInjector {
private:
    UserScript* script_;
public:
    bool ShouldInjectCss(UserScript::RunLocation run_location) const;
};