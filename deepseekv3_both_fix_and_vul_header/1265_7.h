#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstring>

struct FileInfo {
    int statResult;
    std::string path;
};

struct Response {
    FileInfo file_info;
    void end() {}
    void clear() {}
};

struct Adaptor {
    int socket() { return 0; }
    void shutdown_readwrite() {}
    void close() {}
};

struct Parser {
    void clear() {}
};

struct Connection {
    void* get_this() { return nullptr; }
};

namespace asio {
    struct const_buffer {
        const char* data;
        size_t size;
        const_buffer(const char* d, size_t s) : data(d), size(s) {}
    };
    
    void write(int socket, const std::vector<char>& buffers) {}
    
    const_buffer buffer(const char* data) {
        return const_buffer(data, strlen(data));
    }
    
    const_buffer buffer(const char* data, size_t size) {
        return const_buffer(data, size);
    }
}

extern bool is_writing;
extern bool close_connection_;
extern Adaptor adaptor_;
extern Response res;
extern std::vector<char> buffers_;
extern Parser parser_;
extern Connection* connection_;
extern void do_write_sync(const std::vector<asio::const_buffer>& buffers);
extern void check_destroy();

#define CROW_LOG_DEBUG std::cout
#define this connection_->get_this()