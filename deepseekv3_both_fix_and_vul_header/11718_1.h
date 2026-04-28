#include <memory>
#include <string>

class String {
public:
    void clean();
    size_t size() const;
    const char* termedBuf() const;
};

namespace Ssl {
    class ErrorDetail {
    public:
        const char *cn() const;
    private:
        std::unique_ptr<struct X509> broken_cert;
        static bool copy_cn;
    };

    void matchX509CommonNames(struct X509 *cert, String *str, bool copy);
}

struct X509;

const char* html_quote(const char* str);