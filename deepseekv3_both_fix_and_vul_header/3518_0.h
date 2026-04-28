#include <string>

namespace blink {
enum WebReferrerPolicy {
    WebReferrerPolicyDefault
};
}  // namespace blink

struct DropData {
    bool did_originate_from_renderer;
    blink::WebReferrerPolicy referrer_policy;

    DropData();
};