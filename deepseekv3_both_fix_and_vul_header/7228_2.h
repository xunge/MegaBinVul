#include <cstdint>
#include <string>
#include <memory>

namespace Http {
enum class Code {
  InternalServerError
};
}

namespace StreamInfo {
struct ResponseCodeDetails {
  static const ResponseCodeDetails& get();
  const char* ResponsePayloadTooLarge;
};
}

namespace CodeUtility {
std::string toString(Http::Code code);
}

namespace absl {
struct nullopt_t {};
constexpr nullopt_t nullopt;
}

class ActiveStreamEncoderFilter {
public:
  void responseDataTooLarge();
  struct Parent {
    struct State {
      bool encoder_filters_streaming_;
    } state_;
    struct FilterManagerCallbacks {
      void onResponseDataTooLarge();
    } filter_manager_callbacks_;
    void sendLocalReply(Http::Code, const std::string&, void*, absl::nullopt_t, const char*);
  } parent_;
  void onEncoderFilterAboveWriteBufferHighWatermark();
};

#define ENVOY_STREAM_LOG(level, message, parent)