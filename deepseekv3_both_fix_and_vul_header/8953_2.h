#include <string>
#include <map>
#include <vector>
#include <set>
#include <memory>

class GURL {
public:
  GURL();
  explicit GURL(const std::string& url_string);
  bool operator<(const GURL& other) const;
  bool operator==(const GURL& other) const;
};

namespace net {
class URLRequestStatus {
public:
  bool is_success() const;
};

class URLRequest {
public:
  const GURL& original_url() const;
  const GURL& url() const;
  URLRequestStatus status() const;
  int GetResponseCode() const;
};
}  // namespace net

class URLFetcher {
public:
  net::URLRequest* request() const;
  class ResponseWriter {
  public:
    int response_id() const;
    int64_t amount_written() const;
  };
  ResponseWriter* response_writer() const;
  int result() const;
};

class AppCacheEntry {
public:
  enum Type { MASTER };
  AppCacheEntry(Type type, int response_id, int64_t size);
  int response_id() const;
};

class AppCache {
public:
  bool AddOrModifyEntry(const GURL& url, const AppCacheEntry& entry);
};

class AppCacheGroup {
public:
  AppCache* newest_complete_cache() const;
};

class AppCacheHost {
public:
  void AssociateCompleteCache(AppCache* cache);
  void AssociateNoCache(const GURL& manifest_url);
  void RemoveObserver(void* observer);
};

class HostNotifier {
public:
  void AddHost(AppCacheHost* host);
  void SendErrorNotifications(const class AppCacheErrorDetails& details);
};

enum AppCacheErrorReason {
  APPCACHE_MANIFEST_ERROR
};

class AppCacheErrorDetails {
public:
  AppCacheErrorDetails(const std::string& message,
                      AppCacheErrorReason reason,
                      const GURL& url,
                      int status,
                      bool is_cross_origin);
};

struct PendingHosts {
  std::vector<AppCacheHost*> hosts;
  using iterator = std::vector<AppCacheHost*>::iterator;
  iterator begin() { return hosts.begin(); }
  iterator end() { return hosts.end(); }
  void clear() { hosts.clear(); }
};

using PendingMasters = std::map<GURL, PendingHosts>;

class AppCacheUpdateJob {
public:
  enum InternalState { NO_UPDATE, DOWNLOADING, CACHE_FAILURE };
  enum UpdateType { CACHE_ATTEMPT };

  void HandleMasterEntryFetchCompleted(URLFetcher* fetcher);
  void FetchMasterEntries();
  void MaybeCompleteUpdate();
  void HandleCacheFailure(const AppCacheErrorDetails& details,
                         int result,
                         const GURL& url);

  std::string FormatUrlErrorMessage(const char* format,
                                   const GURL& url,
                                   int result,
                                   int response_code);

  InternalState internal_state_;
  std::set<GURL> master_entry_fetches_;
  std::set<GURL> failed_master_entries_;
  std::vector<GURL> added_master_entries_;
  std::vector<int> duplicate_response_ids_;
  int master_entries_completed_;
  PendingMasters pending_master_entries_;
  std::unique_ptr<AppCache> inprogress_cache_;
  AppCacheGroup* group_;
  UpdateType update_type_;
};

#define DCHECK(condition) ((void)0)