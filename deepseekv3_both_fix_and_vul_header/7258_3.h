#include <string>

extern "C" {
    void g_variant_get(void* parameters, const char* format, ...);
    void* g_variant_new(const char* format, ...);
    void g_dbus_method_invocation_return_value(void* invocation, void* variant);
    void g_dbus_method_invocation_return_error(void* invocation, int domain, int code, const char* message);
}

#define G_DBUS_ERROR 0
#define G_DBUS_ERROR_UNKNOWN_METHOD 0

struct GVariant;
struct GDBusMethodInvocation;

class DBusBridge {
public:
    void handleRootMethodCall(const std::string& method_name, GVariant* parameters, GDBusMethodInvocation* invocation);
    bool isAuthorizedByPolkit(GDBusMethodInvocation* invocation);
    std::string getParameter(const std::string& name);
    std::string setParameter(const std::string& name, const std::string& value);
};