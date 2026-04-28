#include <unistd.h>
#include <sys/types.h>

namespace asylo {
namespace system_call {
constexpr int kSYS_read = 0;
}  // namespace system_call

namespace primitives {
class TrustedPrimitives {
 public:
  static void BestEffortAbort(const char* message);
};
}  // namespace primitives

ssize_t EnsureInitializedAndDispatchSyscall(int sysno, int fd, void* buf, size_t count);
}  // namespace asylo

using asylo::EnsureInitializedAndDispatchSyscall;