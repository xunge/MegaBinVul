#include <stdbool.h>
#include <string>

enum class AuthorizationState {
  AUTHORIZED
};

class GURL {
};

class SaveFileResourceHandler {
private:
  AuthorizationState authorization_state_;
public:
  bool OnWillStart(const GURL& url, bool* defer);
};