#include <stdbool.h>
#include <stdint.h>

typedef uintptr_t Address;

class BailoutId {
 public:
  static BailoutId None();
  bool operator!=(const BailoutId& other) const;
};

class DeoptimizationInputData {
 public:
  static DeoptimizationInputData* cast(void* data);
  int DeoptCount();
  class PcValue {
   public:
    int value();
  };
  PcValue* Pc(int i);
  BailoutId AstId(int i);
};

class Code {
 public:
  Address instruction_start();
  bool CanDeoptAt(Address pc);
};

void* deoptimization_data();