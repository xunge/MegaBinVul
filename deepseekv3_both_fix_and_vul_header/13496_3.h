#include <memory>
#include <string>
#include <functional>
#include <map>

struct DataSink {
    std::function<bool(const char* data, size_t data_len)> write;
};

using ContentProvider = std::function<bool(size_t offset, size_t length, DataSink& sink)>;
using ContentProviderWithoutLength = std::function<bool(DataSink& sink)>;

enum class Error {
    Canceled,
    Compression
};

struct Response {};

struct Request {
    std::string body;
    size_t content_length_;
    std::function<bool(size_t, size_t, DataSink&)> content_provider_;
    bool is_chunked_content_provider_;
    std::multimap<std::string, std::string> headers;

    void set_header(const std::string& key, const std::string& val) {
        headers.emplace(key, val);
    }
};

namespace detail {
struct gzip_compressor {
    bool compress(const char* data, size_t data_len, bool last,
                 std::function<bool(const char* compressed_data, size_t compressed_data_len)> callback) {
        return false;
    }
};

struct ContentProviderAdapter {
    ContentProviderWithoutLength provider;
    
    ContentProviderAdapter(ContentProviderWithoutLength p) : provider(std::move(p)) {}
    
    bool operator()(size_t offset, size_t length, DataSink& sink) {
        return provider(sink);
    }
};

template<typename T>
std::unique_ptr<T> make_unique() {
    return std::unique_ptr<T>(new T());
}
}

class ClientImpl {
public:
    bool compress_ = false;
    bool send(Request& req, Response& res, Error& error) { return false; }
    std::unique_ptr<Response> send_with_content_provider(
        Request& req, const char* body, size_t content_length,
        ContentProvider content_provider,
        ContentProviderWithoutLength content_provider_without_length,
        const std::string& content_type, Error& error);
};