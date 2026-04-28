#include <cstddef>

struct SSecurityTLS {
    ~SSecurityTLS();
    void shutdown();
    void* fis;
    void* fos;
    char* keyfile;
    char* certfile;
};

extern "C" {
    void gnutls_global_deinit();
}