#include <set>
#include <vector>
#include <string>

class HostID {
public:
    bool operator<(const HostID& other) const { return id_ < other.id_; }
private:
    std::string id_;
};

class UserScript {
public:
    std::string id() const { return id_; }
private:
    std::string id_;
};

class UserScriptInjector {
public:
    void OnUserScriptsUpdated(const std::set<HostID>& changed_hosts,
                            const std::vector<UserScript*>& scripts);
private:
    HostID host_id_;
    std::string script_id_;
    UserScript* script_;
};