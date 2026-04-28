#include <optional>
#include <string>
#include <algorithm>
#include <vector>

namespace Http {
    enum class Method;
}

struct Path {
    Http::Method method;
};

class PathGroup {
public:
    std::vector<Path> paths(const std::string& name) const;
    std::optional<Path> path(const std::string& name, Http::Method method) const;
};