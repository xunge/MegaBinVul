#include <memory>

class Timeout {
public:
    void cancelTimeout();
};

Timeout resetControlMessages_;
Timeout resetDirectErrors_;
Timeout resetHeaders_;
std::shared_ptr<void> timer_;
int numControlMsgsInCurrentInterval_;
int numDirectErrorHandlingInCurrentInterval_;