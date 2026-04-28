#include <string>
#include <functional>

struct template_t {};
namespace utility {
    void sanitize_filename(std::string&) {}
}
namespace detail {
    struct loader_ref {
        template_t operator()(const std::string&) const { return {}; }
    };
    loader_ref get_loader_ref() { return {}; }
}
template_t compile(const template_t& t) { return t; }