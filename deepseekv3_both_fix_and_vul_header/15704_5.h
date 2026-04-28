#include <string>
#include <vector>
#include <memory>

struct X509;
struct ssl_st;

#define GEN_IPADD 0

namespace absl {
template <typename T>
class Span {
 public:
  Span() : data_(nullptr), size_(0) {}
  Span(const T* data, size_t size) : data_(data), size_(size) {}
  template <typename Container>
  Span(const Container& container) : data_(container.data()), size_(container.size()) {}
  const T* data() const { return data_; }
  size_t size() const { return size_; }
 private:
  const T* data_;
  size_t size_;
};
}

namespace bssl {
template <typename T>
class UniquePtr {
 public:
  explicit UniquePtr(T* ptr) : ptr_(ptr) {}
  ~UniquePtr() { if (ptr_) free(ptr_); }
  T* get() const { return ptr_; }
  T* operator->() const { return ptr_; }
  T* release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }
  explicit operator bool() const { return ptr_ != nullptr; }
  T& operator*() const { return *ptr_; }
 private:
  T* ptr_;
};
}

namespace Utility {
std::vector<std::string> getSubjectAltNames(X509& cert, int type, bool keep_only_first = false);
}

#define ASSERT(expr) ((void)0)

X509* SSL_get_peer_certificate(ssl_st* ssl);
ssl_st* ssl();

class ConnectionInfoImplBase {
protected:
    mutable std::vector<std::string> cached_ip_san_peer_certificate_;
public:
    absl::Span<const std::string> ipSansPeerCertificate() const;
};