#include <memory>

class StreamInfo {
public:
  class CoreResponseFlag {
  public:
    static const CoreResponseFlag UpstreamRequestTimeout;
  };
  
  void setResponseFlag(const CoreResponseFlag& flag);
};

class Timer {};

class UpstreamRequest {
public:
  void onPerTryTimeout();
private:
  std::unique_ptr<Timer> per_try_idle_timeout_;
  StreamInfo stream_info_;
  struct Parent {
    bool downstreamResponseStarted();
    void onPerTryTimeout(UpstreamRequest&);
    struct Callbacks {};
    Callbacks* callbacks();
  } parent_;
};

#define ENVOY_STREAM_LOG(level, message, callbacks)