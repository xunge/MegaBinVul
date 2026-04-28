#include <stdint.h>
#include <vector>

namespace CPU_TYPES {
  enum {
    CPU_TYPE_X86,
    CPU_TYPE_X86_64,
    CPU_TYPE_ARM,
    CPU_TYPE_ARM64
  };
};

namespace details {
  struct x86_thread_state_t {
    uint32_t eip;
  };
  
  struct x86_thread_state64_t {
    uint64_t rip;
  };
  
  struct arm_thread_state_t {
    uint32_t r15;
  };
  
  struct arm_thread_state64_t {
    uint64_t pc;
  };
};

#define LIEF_ERR(msg)

class ThreadCommand {
public:
  uint64_t pc() const;
private:
  int architecture_;
  std::vector<uint8_t> state_;
};