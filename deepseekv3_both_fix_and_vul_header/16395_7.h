#include <stddef.h>
#include <stdint.h>
#include <errno.h>

namespace asylo {
namespace primitives {
class PrimitiveStatus {};
class MessageWriter {
 public:
  void Push(uint64_t value);
};
class MessageReader {
 public:
  void* next_void_ptr();
  int next_int();
  template<typename T> T next();
};
template<> inline void* MessageReader::next<void*>() { return next_void_ptr(); }
template<> inline int MessageReader::next<int>() { return next_int(); }
namespace TrustedPrimitives {
bool IsOutsideEnclave(const void* addr, size_t size);
void BestEffortAbort(const char* message);
}  // namespace TrustedPrimitives
}  // namespace primitives

namespace host_call {
extern const uint32_t kReallocHandler;
primitives::PrimitiveStatus NonSystemCallDispatcher(
    uint32_t handler, primitives::MessageWriter* input,
    primitives::MessageReader* output);
}  // namespace host_call
}  // namespace asylo

int FromkLinuxErrorNumber(int klinux_errno);

void CheckStatusAndParamCount(const asylo::primitives::PrimitiveStatus& status,
                             const asylo::primitives::MessageReader& output,
                             const char* function_name, int expected_count);

using asylo::primitives::MessageWriter;
using asylo::primitives::MessageReader;