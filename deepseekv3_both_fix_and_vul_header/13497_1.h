#include <string>
#include <memory>
#include <utility>
#include <map>
#include <vector>
#include <functional>

struct Request;
struct Response;

namespace detail {
    enum class EncodingType { None, Gzip, Brotli };
    
    struct compressor {
        virtual bool compress(const char* data, size_t data_size, bool last, 
                             std::function<bool(const char* data, size_t data_len)> callback) = 0;
        virtual ~compressor() = default;
    };

    std::string make_multipart_data_boundary();
    EncodingType encoding_type(const Request& req, const Response& res);
    std::pair<size_t, size_t> get_range_offset_and_length(const Request& req, size_t content_length, size_t index);
    std::string make_content_range_header_field(size_t offset, size_t length, size_t content_length);
    size_t get_multipart_ranges_data_length(const Request& req, const Response& res, const std::string& boundary, const std::string& content_type);
    bool make_multipart_ranges_data(const Request& req, const Response& res, const std::string& boundary, const std::string& content_type, std::string& data);

    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    struct gzip_compressor : public compressor {
        bool compress(const char* data, size_t data_size, bool last, 
                     std::function<bool(const char* data, size_t data_len)> callback) override;
    };

    struct brotli_compressor : public compressor {
        bool compress(const char* data, size_t data_size, bool last, 
                     std::function<bool(const char* data, size_t data_len)> callback) override;
    };
}

struct Request {
    std::vector<std::pair<size_t, size_t>> ranges;
};

struct Response {
    std::string body;
    size_t content_length_;
    bool is_chunked_content_provider_;
    std::function<void()> content_provider_;
    int status;
    std::map<std::string, std::string> headers;

    void set_header(const std::string& key, const std::string& value) {
        headers[key] = value;
    }
};

class Server {
public:
    void apply_ranges(const Request& req, Response& res, std::string& content_type, std::string& boundary);
};