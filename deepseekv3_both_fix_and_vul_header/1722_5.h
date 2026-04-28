#include <memory>
#include <utility>
#include <vector>
#include <map>
#include <cstdint>
#include <string>

namespace llvh {
class raw_ostream {
 public:
  raw_ostream &operator<<(const char *);
  raw_ostream &operator<<(int);
  raw_ostream &operator<<(const std::string &);
};
raw_ostream &errs();
} // namespace llvh

using raw_ostream = llvh::raw_ostream;

namespace cl {
enum BytecodeFormatKind { HBC };
extern BytecodeFormatKind BytecodeFormat;
extern int DumpTarget;
const int DumpBytecode = 0;
} // namespace cl

const auto& DumpBytecode = cl::DumpBytecode;

namespace hermes {
template <typename T>
class OptValue {
 public:
  OptValue() : hasValue_(false) {}
  OptValue(T value) : hasValue_(true), value_(value) {}
  bool hasValue() const { return hasValue_; }
  T getValue() const { return value_; }
  T operator*() const { return value_; }
  operator bool() const { return hasValue_; }

 private:
  bool hasValue_;
  T value_;
};
} // namespace hermes

class Module {
 public:
  class Context {
   public:
    class SourceErrorManager {
     public:
      int getErrorCount() const;
    };
    SourceErrorManager &getSourceErrorManager();
  };
  Context &getContext();
};

class BytecodeGenerationOptions {};
class SHA1 {};
class SourceMapGenerator {};

namespace hbc {
class BCProviderFromBuffer {};
class BCProviderFromSrc {
 public:
  static std::unique_ptr<BCProviderFromSrc> createBCProviderFromSrc(std::unique_ptr<class BytecodeModule>);
};
class BytecodeModule {};
std::unique_ptr<BytecodeModule> generateBytecode(
    Module *M,
    llvh::raw_ostream &OS,
    const BytecodeGenerationOptions &genOptions,
    const SHA1 &sourceHash,
    hermes::OptValue<uint32_t> segment,
    SourceMapGenerator *sourceMapGenOrNull,
    std::unique_ptr<BCProviderFromBuffer> baseBCProvider);
} // namespace hbc

using BaseBytecodeMap = std::map<uint32_t, std::unique_ptr<hbc::BCProviderFromBuffer>>;

enum CompileResult { Success, BackendError };

void disassembleBytecode(std::unique_ptr<hbc::BCProviderFromSrc>);
void llvm_unreachable(const char *);