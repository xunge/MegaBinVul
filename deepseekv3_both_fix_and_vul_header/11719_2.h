#include <memory>

extern "C" {
struct X509;
struct X509_name_st;
typedef struct X509_name_st X509_NAME;
X509_NAME *X509_get_subject_name(X509 *x);
int X509_NAME_oneline(X509_NAME *a, char *buf, int size);
}

namespace Ssl {
class ErrorDetail {
public:
    std::unique_ptr<X509, void(*)(X509*)> broken_cert;
    const char *subject() const;
    const char *html_quote(const char *str) const;
};
}