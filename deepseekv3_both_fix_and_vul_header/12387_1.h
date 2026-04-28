#include <cstddef>

class CSecurityTLS {
private:
    bool* fis;
    bool* fos;
    char* cafile;
    char* crlfile;
public:
    ~CSecurityTLS();
    void shutdown(bool);
};

extern "C" {
    void gnutls_global_deinit();
}