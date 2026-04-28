#include <string>
#include <memory>

enum HeaderType {
    CLOUD_TRACE_CONTEXT,
    GRPC_TRACE_CONTEXT
};

class Status {
public:
    bool ok() const { return true; }
};

class Span {
public:
    class TraceSpan {
    public:
        std::string span_id() const { return ""; }
    };
    TraceSpan* trace_span() { return &trace_span_; }
private:
    TraceSpan trace_span_;
};

class CloudTrace {
public:
    std::string ToTraceContextHeader(const std::string& span_id) { return ""; }
    HeaderType header_type() const { return CLOUD_TRACE_CONTEXT; }
};

class Request {
public:
    Status AddHeaderToBackend(const std::string& header_name, const std::string& header_value, bool overwrite = false) { return Status(); }
};

class Env {
public:
    void LogError(const std::string& message) {}
};

class ServiceContext {
public:
    Env* env() { return &env_; }
private:
    Env env_;
};

class RequestContext {
public:
    void StartBackendSpanAndSetTraceContext();
    CloudTrace* cloud_trace() { return cloud_trace_.get(); }
    Request* request() { return request_; }
    ServiceContext* service_context() { return service_context_; }
    Span* CreateSpan(CloudTrace* trace, const std::string& name) { return new Span(); }

private:
    std::unique_ptr<CloudTrace> cloud_trace_;
    std::unique_ptr<Span> backend_span_;
    Request* request_;
    ServiceContext* service_context_;
};

const std::string kCloudTraceContextHeader = "cloud-trace-context";
const std::string kGRpcTraceContextHeader = "grpc-trace-context";