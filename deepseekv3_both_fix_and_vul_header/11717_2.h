#include <memory>

struct X509;
struct X509_name;

extern "C" {
X509_name* X509_get_issuer_name(X509*);
int X509_NAME_oneline(X509_name*, char*, int);
}

namespace Ssl {
class ErrorDetail {
public:
    std::unique_ptr<X509, void(*)(X509*)> broken_cert;
    const char *ca_name() const;
    const char *html_quote(const char *str) const;
};
}