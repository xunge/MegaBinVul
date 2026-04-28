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
    bool hasPath(const std::string& name, Http::Method method) const;
};