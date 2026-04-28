#include <cstdint>
#include <cstddef>
#include <iostream>

namespace asylo {
namespace primitives {
class TrustedPrimitives {
 public:
  static bool IsOutsideEnclave(const void* buf, uint64_t size);
  static void BestEffortAbort(const char* message);
};
}  // namespace primitives

int Restore(const char* input, size_t input_len, char** output, size_t* output_len);
}  // namespace asylo

#define LOG(severity) std::cerr