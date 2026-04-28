#include <cstdint>
#include <cerrno>
#include <cstddef>

struct MessageWriter {
  template <typename T>
  void Push(uint64_t value);
};

struct MessageReader {
  template <typename T>
  T next();
};

namespace asylo {
namespace host_call {
constexpr int kLocalLifetimeAllocHandler = 0;
}  // namespace host_call
}  // namespace asylo

int NonSystemCallDispatcher(int handler, MessageWriter* input,
                           MessageReader* output);

class TrustedPrimitives {
 public:
  static bool IsOutsideEnclave(const void* addr, size_t size);
  static void BestEffortAbort(const char* message);
};

void CheckStatusAndParamCount(int status, MessageReader& output,
                             const char* function_name, int param_count);

int FromkLinuxErrorNumber(int klinux_errno);

void enc_untrusted_disable_waiting(int32_t* queue);