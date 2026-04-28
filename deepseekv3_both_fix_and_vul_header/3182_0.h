#include <stddef.h>
#include <stdint.h>

#define DCHECK(condition) 
#define DCHECK_EQ(val1, val2) 

enum IoState {
  STATE_REQUEST_SENT,
  STATE_READ_HEADERS,
  STATE_READ_HEADERS_COMPLETE,
  STATE_DONE
};

enum Error {
  OK,
  ERR_IO_PENDING,
  ERR_CONNECTION_CLOSED
};

class CompletionCallback {
public:
  bool is_null() const { return false; }
};

class IOBuffer {
public:
  int offset() { return 0; }
  void set_offset(int offset) {}
};

class HttpStreamParser {
private:
  IoState io_state_;
  CompletionCallback callback_;
  int read_buf_unused_offset_;
  IOBuffer* read_buf_;

public:
  int DoLoop(int result) { return 0; }
  int ReadResponseHeaders(const CompletionCallback& callback);
};