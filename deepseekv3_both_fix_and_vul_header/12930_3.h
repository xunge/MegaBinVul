#include <cstdint>
#include <string>
#include <memory>

namespace Http {
enum class GoAwayErrorCode {
  NoError
};
enum class StreamResetReason {
  LocalReset
};
class StreamEncoder {
public:
  class Stream {
  public:
    void resetStream(StreamResetReason);
  };
  Stream& getStream();
};
}  // namespace Http

namespace envoy {
namespace data {
namespace core {
namespace v3 {
enum HealthStatus {
  NETWORK
};
}  // namespace v3
}  // namespace core
}  // namespace data
}  // namespace envoy

class Host;

class Client {
public:
  void close();
};

class HostUtility {
public:
  static std::string healthFlagsToString(const Host&);
};

class GrpcHealthCheckerImpl {
public:
  class GrpcActiveHealthCheckSession {
  public:
    void onGoAway(Http::GoAwayErrorCode error_code);
  private:
    std::unique_ptr<Http::StreamEncoder> request_encoder_;
    bool received_no_error_goaway_ = false;
    bool expect_reset_ = false;
    Client* client_;
    Host* host_;
    
    void handleFailure(envoy::data::core::v3::HealthStatus);
  };
};

#define ENVOY_CONN_LOG(level, fmt, client, ...)