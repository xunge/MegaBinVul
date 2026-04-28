#include <iostream>
#include <cstdlib>

#define CHECK_LE(a, b) ((a) <= (b) ? (void)0 : std::abort())
#define LOG(severity) std::cerr
#define ERROR 1

enum PrintResult {
  OK,
  FAIL_PRINT
};

class PrintWebViewHelper {
public:
  void OnPrintingDone(bool success);
  void DidFinishPrinting(PrintResult result);
  int ipc_nesting_level_;
  bool notify_browser_of_print_failure_;
};