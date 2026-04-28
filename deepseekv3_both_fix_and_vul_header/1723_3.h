#include <memory>
#include <utility>
#include <iostream>

namespace llvh {
class raw_ostream {
public:
  raw_ostream &operator<<(const char *str);
  raw_ostream &operator<<(unsigned num);
};
raw_ostream &errs();
} // namespace llvh

namespace cl {
enum BytecodeFormatKind { HBC };
extern BytecodeFormatKind BytecodeFormat;
} // namespace cl

class Module;
class Function;
struct BytecodeGenerationOptions;

namespace hbc {
struct BytecodeModule {};
struct BCProviderFromSrc {
  static std::unique_ptr<BCProviderFromSrc> createBCProviderFromSrc(BytecodeModule BM);
};
BytecodeModule generateBytecodeModule(Module *M, Function *F, const BytecodeGenerationOptions &genOptions);
} // namespace hbc

class Context;
class SourceErrorManager;

class Module {
public:
  std::shared_ptr<Context> shareContext();
  Function *getTopLevelFunction();
};

class Function {};

class SourceErrorManager {
public:
  unsigned getErrorCount();
};

class Context {
public:
  SourceErrorManager &getSourceErrorManager();
};

enum CompileResultStatus { Success, BackendError, InvalidFlags };

struct CompileResult {
  CompileResultStatus status;
  std::unique_ptr<hbc::BCProviderFromSrc> bytecodeProvider;

  CompileResult(CompileResultStatus s) : status(s) {}
  operator CompileResultStatus() const { return status; }
};

void llvm_unreachable(const char *msg);