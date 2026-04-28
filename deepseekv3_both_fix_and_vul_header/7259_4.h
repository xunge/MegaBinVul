#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

class GVariant;
class GDBusMethodInvocation;

typedef int gboolean;
#define G_VARIANT_TYPE_ARRAY 0
#define G_DBUS_ERROR 0
#define G_DBUS_ERROR_UNKNOWN_METHOD 0

class Rule {
public:
    enum class Target;
    uint32_t getRuleID() const;
    std::string toString() const;
    static Target targetFromInteger(uint32_t target_integer);
};

class DBusBridge {
public:
    bool isAuthorizedByPolkit(GDBusMethodInvocation* invocation);
    std::vector<Rule> listDevices(const std::string& query);
    uint32_t applyDevicePolicy(uint32_t device_id, Rule::Target target, bool permanent);
    void handleDevicesMethodCall(const std::string& method_name, GVariant* parameters, GDBusMethodInvocation* invocation);
};

#define USBGUARD_LOG(level) std::cout
#define g_variant_get(...)
#define g_variant_builder_new(...) nullptr
#define g_variant_builder_add(...)
#define g_variant_new(...) nullptr
#define g_dbus_method_invocation_return_value(...)
#define g_variant_builder_unref(...)
#define g_dbus_method_invocation_return_error(...)