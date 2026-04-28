#include <string>
#include <memory>

struct ExtensionFunction {
    struct ResponseAction {};
    class Args {
    public:
        bool GetString(int, std::string*) { return true; }
    };
    std::unique_ptr<Args> args_;
};

class RuntimeSetUninstallURLFunction : public ExtensionFunction {
public:
    ResponseAction Run();
    std::string extension_id() { return ""; }
    void* browser_context() { return nullptr; }
};

class ExtensionPrefs {
public:
    static ExtensionPrefs* Get(void*) { return nullptr; }
};

class ErrorUtils {
public:
    static std::string FormatErrorMessage(const char*, const std::string&) { return ""; }
};

class GURL {
public:
    GURL(const std::string&) {}
    bool is_valid() { return true; }
    bool SchemeIsHTTPOrHTTPS() { return true; }
};

const char kInvalidUrlError[] = "";

void SetUninstallURL(ExtensionPrefs*, const std::string&, const std::string&) {}

ExtensionFunction::ResponseAction Error(const std::string& msg) { return {}; }
ExtensionFunction::ResponseAction Error(const char* error, const std::string& details) { return {}; }
ExtensionFunction::ResponseAction RespondNow(const ExtensionFunction::ResponseAction&) { return {}; }
ExtensionFunction::ResponseAction NoArguments() { return {}; }
#define EXTENSION_FUNCTION_VALIDATE(expr) (void)(expr)