#include <stdbool.h>

struct AppCacheHost {
    bool was_select_cache_called();
    bool SelectCacheForWorker(int parent_process_id, int parent_host_id);
};

class AppCacheBackendImpl {
public:
    AppCacheHost* GetHost(int host_id);
    bool SelectCacheForWorker(int host_id, int parent_process_id, int parent_host_id);
};