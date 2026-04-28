#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define CHECK(condition)
#define DCHECK(condition)

class AppCacheHost {
public:
    std::string pending_master_entry_url() const;
};

class AppCacheUpdateJob {
public:
    typedef std::vector<AppCacheHost*> PendingHosts;
    typedef std::map<std::string, PendingHosts> PendingMasters;
    PendingMasters pending_master_entries_;

    void OnDestructionImminent(AppCacheHost* host);
};