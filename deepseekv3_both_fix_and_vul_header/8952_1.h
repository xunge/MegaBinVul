#include <memory>
#include <vector>
#include <cassert>

#define DCHECK assert
#define CHECK assert

class AppCacheUpdateJob;
class AppCacheService;
class AppCacheGroup;
class AppCache;

enum InternalState {
  COMPLETED
};

class AppCacheGroup {
public:
  enum Status {
    IDLE
  };
  void SetUpdateAppCacheStatus(Status status);
};

class AppCacheService {
public:
  void RemoveObserver(AppCacheUpdateJob* job);
};

class AppCacheUpdateJob {
private:
  AppCacheService* service_;
  InternalState internal_state_;
  std::shared_ptr<AppCache> inprogress_cache_;
  std::vector<int> pending_master_entries_;
  void* manifest_fetcher_;
  std::vector<int> pending_url_fetches_;
  std::vector<int> master_entry_fetches_;
  AppCacheGroup* group_;

public:
  ~AppCacheUpdateJob();
  void Cancel();
};