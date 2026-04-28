#include <stdint.h>

#define LLVM_UNLIKELY(x) (x)

enum class ExecutionStatus { RETURNED };

struct Runtime {};

extern bool isLazy();
extern ExecutionStatus lazyCompileImpl(Runtime &runtime);