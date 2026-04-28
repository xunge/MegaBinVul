#include <cassert>
#include <string>
#include <memory>
#include <filesystem>
#include <cstdio>

namespace fs = std::filesystem;

enum class Status { kOK };
enum class methods { kGet };

class Url {
public:
    class Path {
    public:
        std::string path() const;
        operator std::string() const { return path(); }
        operator fs::path() const { return fs::path(path()); }
    };
    static std::string DecodeUnsafe(const std::string& str);
    Path url() const;
    Path path() const { return url(); }
};

class Request {
public:
    methods method() const;
    Url url() const;
};

class Response {
public:
    Response(Status status);
    void SetContentType(const std::string& type, const std::string& charset);
    void SetBody(std::shared_ptr<class FileBody> body, bool own);
};

class FileBody {
public:
    FileBody(const fs::path& path, size_t chunk_size);
};

class Error {
public:
    std::string message() const;
};

namespace media_types {
    std::string FromExtension(const std::string& extension);
}

namespace utility {
    fs::path TranslatePath(const std::string& path);
}

#define LOG_INFO(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define LOG_ERRO(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)

using RequestPtr = std::shared_ptr<Request>;
using ResponsePtr = std::shared_ptr<Response>;

class Server {
    fs::path doc_root_;
    size_t file_chunk_size_;
public:
    ResponsePtr ServeStatic(RequestPtr request);
};