#include <memory>

namespace AutofillAgent {
class LegacyAutofillAgent {
public:
    void FocusChangeComplete();
private:
    std::shared_ptr<LegacyAutofillAgent> agent_;
};
}