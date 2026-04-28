#include <string>
#include <memory>

class HttpStreamParser {
public:
    void CalculateResponseBodySize();
private:
    struct Response {
        struct Headers {
            int response_code();
            bool IsChunkEncoded();
            int GetContentLength();
        };
        Headers* headers;
    };
    struct Request {
        std::string method;
    };
    Response* response_;
    Request* request_;
    int response_body_length_;
    class HttpChunkedDecoder {
    public:
        HttpChunkedDecoder() = default;
    };
    std::unique_ptr<HttpChunkedDecoder> chunked_decoder_;
};