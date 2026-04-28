#include <vector>
#include <string>
#include <map>
#include <set>

struct URL {
    std::string path() const;
};

struct FileInfo {
    URL url() const;
};

namespace UserScript {
    typedef std::vector<FileInfo> FileList;
    enum RunLocation {};
}

struct HostID {
    int id() const;
    int id_;
};

struct ScriptsRunInfo {
    size_t num_js;
    size_t num_css;
    std::map<int, std::set<std::string>> executing_scripts;
};

class UserScriptInjector {
public:
    void GetRunInfo(ScriptsRunInfo*, UserScript::RunLocation) const;
private:
    HostID host_id_;
    class Script {
    public:
        const UserScript::FileList& js_scripts() const;
        const UserScript::FileList& css_scripts() const;
    };
    Script* script_;
    bool ShouldInjectJs(UserScript::RunLocation run_location) const;
    bool ShouldInjectCss(UserScript::RunLocation run_location) const;
};