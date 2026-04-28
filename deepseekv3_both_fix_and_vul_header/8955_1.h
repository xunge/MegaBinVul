#include <stdint.h>

class AppCacheHost {
public:
    bool was_select_cache_called() const;
    bool SelectCacheForSharedWorker(int64_t appcache_id);
};

class AppCacheBackendImpl {
public:
    AppCacheHost* GetHost(int host_id);
    bool SelectCacheForSharedWorker(int host_id, int64_t appcache_id);
};

typedef int64_t int64;