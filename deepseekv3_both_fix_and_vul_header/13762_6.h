#include <sys/uio.h>
#include <cstdint>
#include <cstring>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <iostream>

enum WriteResultType {
  WRITE_ERROR
};

enum SSLError {
  EARLY_WRITE
};

enum WriteFlags {
  CORK = 1,
  NONE = 0
};

constexpr WriteFlags kEorRelevantWriteFlags = static_cast<WriteFlags>(0);

class SSLException {
public:
  SSLException(SSLError error);
};

class AsyncSocket {
public:
  enum State {};
  enum WriteFlags {
    CORK = 1,
    NONE = 0
  };
  struct WriteResult {
    WriteResult(WriteResultType, std::unique_ptr<SSLException>);
    WriteResult(ssize_t);
    ssize_t writeReturn;
  };
  virtual WriteResult performWrite(const iovec*, uint32_t, WriteFlags, uint32_t*, uint32_t*);
};

class AsyncSSLSocket : public AsyncSocket {
public:
  enum SSLStateEnum {
    STATE_UNENCRYPTED,
    STATE_ESTABLISHED
  };
  
  enum {
    SSL_ERROR_WANT_WRITE = 2
  };

  SSLStateEnum sslState_;
  int fd_;
  State state_;
  int eventFlags_;
  uint32_t minWriteSize_;
  bool corkCurrentWrite_;
  WriteFlags appEorByteWriteFlags_;
  struct SSL;
  std::unique_ptr<SSL> ssl_;
  static constexpr size_t MAX_STACK_BUF_SIZE = 1024;
  static const WriteFlags kEorRelevantWriteFlags;

  ssize_t eorAwareSSLWrite(const std::unique_ptr<SSL>&, const void*, int, bool);
  WriteResult interpretSSLError(int, int);
  int SSL_get_error(SSL* ssl, int ret);
  WriteResult performWrite(const iovec* vec, uint32_t count, WriteFlags flags, uint32_t* countWritten, uint32_t* partialWritten) override;
  static bool isSet(WriteFlags flags, WriteFlags test);
};

#define SCOPE_EXIT auto _scopeExitGuard_ = [&]()
#define LOG(severity) std::cout
enum { ERROR };

inline AsyncSocket::WriteFlags operator&(AsyncSocket::WriteFlags a, AsyncSocket::WriteFlags b) {
    return static_cast<AsyncSocket::WriteFlags>(static_cast<int>(a) & static_cast<int>(b));
}

inline bool operator!=(AsyncSocket::WriteFlags a, AsyncSocket::WriteFlags b) {
    return static_cast<int>(a) != static_cast<int>(b);
}

namespace folly {
enum WriteFlags {
  NONE = 0
};
}