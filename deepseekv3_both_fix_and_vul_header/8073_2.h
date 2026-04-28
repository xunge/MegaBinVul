#include <functional>

namespace net {
class AuthChallengeInfo;
class URLRequest {
 public:
  int load_flags() const;
  const char* url() const;
};
const int LOAD_MAIN_FRAME = 0;
}  // namespace net

class LoginHandler {
 public:
  static LoginHandler* Create(net::AuthChallengeInfo*, net::URLRequest*);
  static void LoginDialogCallback(const char*, net::AuthChallengeInfo*, 
                                LoginHandler*, bool);
};

void LoginDialogCallback(const char*, net::AuthChallengeInfo*, 
                        LoginHandler*, bool);

class BrowserThread {
 public:
  enum ID { UI };
  static void PostTask(ID, const char*, std::function<void()>);
};

const char* FROM_HERE = "";

namespace base {
template <typename T>
class RetainedRef {
 public:
  explicit RetainedRef(T*);
};
template <typename... Args>
auto Bind(Args&&... args) -> std::function<void()>;
}  // namespace base