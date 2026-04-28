#include <string>
#include <memory>
#include <cstdint>

namespace Grpc {
namespace Status {
enum GrpcStatus {
  OK,
  CANCELLED,
  UNKNOWN,
  INVALID_ARGUMENT,
  DEADLINE_EXCEEDED,
  NOT_FOUND,
  ALREADY_EXISTS,
  PERMISSION_DENIED,
  RESOURCE_EXHAUSTED,
  FAILED_PRECONDITION,
  ABORTED,
  OUT_OF_RANGE,
  UNIMPLEMENTED,
  INTERNAL,
  UNAVAILABLE,
  DATA_LOSS,
  UNAUTHENTICATED
};
}
}

namespace envoy {
namespace data {
namespace core {
namespace v3 {
enum HealthCheckFailureType {
  ACTIVE
};
}
}
}
}

namespace Http {
enum StreamResetReason {
  LocalReset
};
}

class GrpcHealthCheckerImpl {
public:
  bool reuse_connection_;
  
  class GrpcActiveHealthCheckSession {
  public:
    void onRpcComplete(Grpc::Status::GrpcStatus grpc_status, const std::string& grpc_message, bool end_stream);
  private:
    bool received_no_error_goaway_;
    bool expect_reset_;
    class HttpStreamEncoder {
    public:
      class Stream {
      public:
        void resetStream(Http::StreamResetReason reason);
      };
      Stream& getStream();
    };
    std::unique_ptr<HttpStreamEncoder> request_encoder_;
    class Client {
    public:
      void close();
    };
    std::unique_ptr<Client> client_;
    GrpcHealthCheckerImpl& parent_;

    void logHealthCheckStatus(Grpc::Status::GrpcStatus grpc_status, const std::string& grpc_message);
    bool isHealthCheckSucceeded(Grpc::Status::GrpcStatus grpc_status);
    void handleSuccess(bool first_check);
    void handleFailure(envoy::data::core::v3::HealthCheckFailureType failure_type);
    void resetState();
  };
};