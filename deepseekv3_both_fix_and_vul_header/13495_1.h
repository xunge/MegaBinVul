#include <string>
#include <vector>
#include <map>
#include <functional>

class Stream {};
class DataSink {};

namespace detail {
    class BufferStream {
    public:
        void write_format(const char* format, ...);
        std::vector<char>& get_buffer();
    };

    void write_headers(BufferStream& bstrm, const std::multimap<std::string, std::string>& headers);
    bool write_data(Stream& strm, const char* data, size_t size);
    std::string encode_url(const std::string& s);
}

class Request {
public:
    std::string method;
    std::string path;
    std::multimap<std::string, std::string> headers;
    std::string body;
    size_t content_length_;
    bool is_chunked_content_provider_;
    std::function<void(size_t, size_t, DataSink&)> content_provider_;

    bool has_header(const std::string& key) const;
    void set_header(const std::string& key, const std::string& val);
};

enum class Error {
    Write
};

class ClientImpl {
public:
    bool write_request(Stream& strm, Request& req, bool close_connection, Error& error);
protected:
    std::string host_;
    std::string host_and_port_;
    int port_;
    bool url_encode_;
    std::string basic_auth_username_;
    std::string basic_auth_password_;
    std::string proxy_basic_auth_username_;
    std::string proxy_basic_auth_password_;
    std::string bearer_token_auth_token_;
    std::string proxy_bearer_token_auth_token_;

    bool is_ssl() const;
    bool write_content_with_provider(Stream& strm, Request& req, Error& error);
    std::pair<std::string, std::string> make_basic_authentication_header(
        const std::string& username, const std::string& password, bool is_proxy);
    std::pair<std::string, std::string> make_bearer_token_authentication_header(
        const std::string& token, bool is_proxy);
};

#define CPPHTTPLIB_VERSION "0.1"