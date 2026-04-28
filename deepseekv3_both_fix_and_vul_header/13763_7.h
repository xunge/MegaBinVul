#include <cerrno>
#include <memory>
#include <iostream>

#define SSL_ERROR_WANT_READ 2
#define ERROR 0
#define LOG(x) std::cerr
#define VLOG(x) std::cout

enum SSLError {
  INVALID_RENEGOTIATION
};

class SSLException {
public:
  SSLException(SSLError error);
  SSLException(int error, unsigned long errError, int rc, int errno_);
};

class AsyncSocket {
public:
  struct WriteResult {
    enum WriteResultEnum {
      WRITE_ERROR
    };
    WriteResult(WriteResultEnum result, std::unique_ptr<SSLException> ex) {}
    WriteResult(int bytes) {}
  };
  static constexpr AsyncSocket::WriteResult::WriteResultEnum WRITE_ERROR = AsyncSocket::WriteResult::WRITE_ERROR;
};

class AsyncSSLSocket : public AsyncSocket {
public:
  WriteResult interpretSSLError(int rc, int error);
private:
  int fd_;
  int state_;
  int sslState_;
  int eventFlags_;
  bool zero_return(int error, int rc, int errno_);
};

unsigned long ERR_get_error();
const char* ERR_func_error_string(unsigned long e);
const char* ERR_reason_error_string(unsigned long e);