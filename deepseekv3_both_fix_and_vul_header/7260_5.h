#include <string>
#include <vector>
#include <cstdint>

class Rule {
public:
    uint32_t getRuleID() const;
    std::string toString() const;
};

typedef void* GVariant;
typedef void* GDBusMethodInvocation;
typedef int gboolean;
#define G_DBUS_ERROR 0
#define G_DBUS_ERROR_UNKNOWN_METHOD 0
#define G_VARIANT_TYPE_ARRAY "a*"

class DBusBridge {
public:
    bool isAuthorizedByPolkit(GDBusMethodInvocation* invocation);
    std::vector<Rule> listRules(const std::string& label);
    uint32_t appendRule(const std::string& rule_spec, uint32_t parent_id, bool permanent);
    void removeRule(uint32_t rule_id);
    void handlePolicyMethodCall(const std::string& method_name, GVariant* parameters, GDBusMethodInvocation* invocation);
};

static inline void g_variant_get(GVariant*, const char*, ...) {}
static inline GVariant* g_variant_builder_new(const char*) { return nullptr; }
static inline void g_variant_builder_add(GVariant*, const char*, ...) {}
static inline GVariant* g_variant_new(const char*, ...) { return nullptr; }
static inline void g_variant_builder_unref(GVariant*) {}
static inline void g_dbus_method_invocation_return_value(GDBusMethodInvocation*, GVariant*) {}
static inline void g_dbus_method_invocation_return_error(GDBusMethodInvocation*, int, int, const char*) {}