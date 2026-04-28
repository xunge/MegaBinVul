#include <iostream>

struct InitMlir {
  InitMlir(int* argc, char*** argv) {}
};

namespace mlir {
  void registerAsmPrinterCLOptions() {}
  int mlirTranslateMain(int argc, char** argv, const char* toolName) { return 0; }
  bool failed(int status) { return status != 0; }
}

namespace tensorflow {
  using ::InitMlir;
}

using mlir::failed;