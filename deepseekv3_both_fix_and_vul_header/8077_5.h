#include <string>
#include <set>
#include <memory>
#include <cassert>

#define DCHECK(condition) assert(condition)
#define DCHECK_EQ(val1, val2) assert((val1) == (val2))

class GURL {
 public:
  GURL(const std::string& url);
  GURL(const GURL& other);
  bool operator<(const GURL& other) const;
};

class ProxyInfo;
class ProxyDelegate;

class NetLog {
 public:
  enum Type {
    TYPE_PROXY_SERVICE,
    TYPE_PROXY_SERVICE_WAITING_FOR_INIT_PAC
  };
};

class BoundNetLog {
 public:
  void BeginEvent(NetLog::Type type) const;
};

class CompletionCallback {
 public:
  bool is_null() const;
};

class TimeTicks {
 public:
  TimeTicks();
  static TimeTicks Now();
};

class PacRequest {
 public:
  PacRequest(class ProxyService* service, const GURL& url, const std::string& method,
            int load_flags, ProxyDelegate* delegate, ProxyInfo* result,
            const CompletionCallback& callback, const BoundNetLog& net_log);
  int Start();
  int QueryDidComplete(int result);
  BoundNetLog* net_log();
  bool operator<(const PacRequest& other) const;
};

template <typename T>
class scoped_refptr {
 public:
  explicit scoped_refptr(T* ptr);
  T* get() const;
  T* operator->() const;
  bool operator<(const scoped_refptr<T>& other) const;
};

class ConfigService {
 public:
  void OnLazyPoll();
};

class ScriptPoller {
 public:
  void OnLazyPoll();
  ScriptPoller* get();
};

enum State {
  STATE_NONE,
  STATE_READY
};

enum Error {
  ERR_IO_PENDING
};

class ProxyService {
 public:
  bool CalledOnValidThread();
  void ApplyProxyConfigIfAvailable();
  int TryToCompleteSynchronously(const GURL& url, int load_flags,
                               ProxyDelegate* proxy_delegate, ProxyInfo* result);
  int DidFinishResolvingProxy(const GURL& url, const std::string& method,
                            int load_flags, ProxyDelegate* proxy_delegate,
                            ProxyInfo* result, int rv, const BoundNetLog& net_log,
                            TimeTicks time, bool was_pac_request);
  bool ContainsPendingRequest(PacRequest* req);
  GURL SanitizeUrl(const GURL& url, int policy);
  GURL SimplifyUrlForRequest(const GURL& url);
  
  int ResolveProxyHelper(const GURL& raw_url,
                        const std::string& method,
                        int load_flags,
                        ProxyInfo* result,
                        const CompletionCallback& callback,
                        PacRequest** pac_request,
                        ProxyDelegate* proxy_delegate,
                        const BoundNetLog& net_log);

  State current_state_;
  std::set<scoped_refptr<PacRequest>> pending_requests_;
  ConfigService* config_service_;
  std::unique_ptr<ScriptPoller> script_poller_;
  int sanitize_url_policy_;
};