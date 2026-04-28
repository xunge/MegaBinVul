#include <string>
#include <functional>

struct net {
  struct URLRequestStatus {
    bool is_success() const { return false; }
    bool is_io_pending() const { return false; }
  };
};

class SaveFileManager {
public:
    void SaveFinished(int, int, bool) {}
};

class BrowserThread {
public:
  enum ID {
    FILE
  };
  template <typename... Args>
  static void PostTask(ID, const char*, Args&&... args) {}
};

namespace base {
template <typename F, typename... Args>
auto Bind(F&& f, Args&&... args) {
    return std::bind(std::forward<F>(f), std::forward<Args>(args)...);
}
}

enum class AuthorizationState {
  AUTHORIZED, UNAUTHORIZED
};

struct SaveFileResourceHandler {
  AuthorizationState authorization_state_;
  SaveFileManager* save_manager_;
  int save_item_id_;
  int save_package_id_;
  void* read_buffer_;

  void OnResponseCompleted(const net::URLRequestStatus&, const std::string&, bool*);
};

#define FROM_HERE ""
#define DCHECK(expr)