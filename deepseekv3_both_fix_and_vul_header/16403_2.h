#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdint.h>
#include <cstring>
#include <algorithm>

struct klinux_sockaddr;
struct sockaddr;

class MessageWriter {
 public:
  template <typename T> void Push(T value);
};

class MessageReader {
 public:
  template <typename T> T next();
  class Buffer {
   public:
    const void* data() const;
    size_t size() const;
    template <typename T> const T* As() const;
  };
  Buffer next();
};

enum class Status;

Status NonSystemCallDispatcher(int handler, MessageWriter* input, MessageReader* output);

int TokLinuxRecvSendFlag(int flags);
int FromkLinuxErrorNumber(int klinux_errno);
void FromkLinuxSockAddr(const struct klinux_sockaddr* klinux_addr, size_t klinux_addr_len,
                        struct sockaddr* out_addr, socklen_t* out_addrlen,
                        void (*abort_func)(const char*));
void CheckStatusAndParamCount(Status status, MessageReader& output, const char* name, int count);

namespace asylo {
namespace host_call {
constexpr int kRecvFromHandler = 0;
}  // namespace host_call
namespace primitives {
class TrustedPrimitives {
 public:
  static void BestEffortAbort(const char* message);
};
}  // namespace primitives
}  // namespace asylo

using asylo::primitives::TrustedPrimitives;