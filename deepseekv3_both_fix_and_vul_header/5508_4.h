#include <cstdint>
#include <map>
#include <string>
#include <cassert>

#define DCHECK(condition) assert(condition)
#define DCHECK_EQ(val1, val2) assert((val1) == (val2))

using int64 = int64_t;

class GURL {
public:
    GURL() = default;
    explicit GURL(const std::string& url_spec) {}
    bool operator<(const GURL& other) const { return false; }
};

class ServiceWorkerDatabase {
public:
    struct ResourceRecord {
        int64 resource_id;
        GURL url;
        int size;
        ResourceRecord() : resource_id(0), url(), size(0) {}
        ResourceRecord(int64 id, const GURL& u, int s) : resource_id(id), url(u), size(s) {}
    };
};

class ServiceWorkerStorage {
public:
    void StoreUncommittedResponseId(int64 resource_id) {}
};

class ServiceWorkerVersion {
public:
    enum Status {
        NEW,
        INSTALLING,
        INSTALLED,
        ACTIVATING,
        ACTIVATED,
        REDUNDANT
    };
};

class ServiceWorkerScriptCacheMap {
public:
    int64 LookupResourceId(const GURL& url) { return 0; }
    void NotifyStartedCaching(const GURL& url, int64 resource_id);
    
    std::map<GURL, ServiceWorkerDatabase::ResourceRecord> resource_map_;
    
    class Context {
    public:
        ServiceWorkerStorage* storage() { return nullptr; }
    };
    Context* context_ = nullptr;
    
    class Owner {
    public:
        ServiceWorkerVersion::Status status() { return ServiceWorkerVersion::NEW; }
    };
    Owner* owner_ = nullptr;
};

const int64 kInvalidServiceWorkerResponseId = -1;