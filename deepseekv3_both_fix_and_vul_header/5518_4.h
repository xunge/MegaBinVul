#include <stdint.h>
#include <memory>

#define OK 0
#define ERR_TUNNEL_CONNECTION_FAILED -1
#define ERR_HTTPS_PROXY_TUNNEL_RESPONSE -2

struct HttpVersion {
    int major;
    int minor;
    HttpVersion(int m, int n) : major(m), minor(n) {}
    bool operator<(const HttpVersion& other) const {
        return major < other.major || (major == other.major && minor < other.minor);
    }
};

struct NetLog {
    enum Type {
        TYPE_HTTP_TRANSACTION_READ_TUNNEL_RESPONSE_HEADERS
    };
    void AddEvent(Type type, void* callback) {}
};

struct HttpResponseHeaders {
    int response_code() const { return 0; }
    HttpVersion GetParsedHttpVersion() const { return HttpVersion(1,1); }
    static void NetLogCallback(HttpResponseHeaders* headers) {}
};

struct HostPortPair {
    static HostPortPair FromURL(const char* url) { return HostPortPair(); }
};

struct URLRequest {
    const char* url;
};

struct HttpStreamParser {
    bool IsMoreDataBuffered() const { return false; }
    bool IsConnectionReused() const { return false; }
    void reset() {}
};

struct Transport {
    bool GetLoadTimingInfo(bool reused, void* timing_info) const { return false; }
    void reset() {}
};

struct ProxyDelegate {
    void OnTunnelHeadersReceived(HostPortPair host_port, const char* proxy_server, const HttpResponseHeaders& headers) {}
};

struct AuthCredentials {
    void* get() { return nullptr; }
};

struct LoadTimingInfo {
};

namespace base {
    template<typename T, typename U>
    void* Bind(T callback, U arg) { return nullptr; }
}

class HttpProxyClientSocket {
private:
    struct Response {
        HttpResponseHeaders* headers;
    } response_;
    NetLog net_log_;
    ProxyDelegate* proxy_delegate_;
    URLRequest request_;
    const char* proxy_server_;
    std::unique_ptr<HttpStreamParser> http_stream_parser_;
    std::unique_ptr<Transport> transport_;
    std::unique_ptr<AuthCredentials> auth_;
    bool is_https_proxy_;
    bool redirect_has_load_timing_info_;
    LoadTimingInfo redirect_load_timing_info_;
    int next_state_;

    enum State {
        STATE_DONE
    };

    void LogBlockedTunnelResponse() {}
    bool SanitizeProxyRedirect(Response* response) { return false; }
    bool SanitizeProxyRedirect(Response* response, const URLRequest& request) { return false; }
    bool SanitizeProxyRedirect(Response* response, const char* url) { return false; }
    bool SanitizeProxyAuth(Response* response) { return false; }
    int HandleProxyAuthChallenge(void* auth, Response* response, NetLog net_log) { return 0; }

public:
    int DoReadHeadersComplete(int result);
};