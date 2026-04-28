#include <vector>

enum class Result {
  Ok,
  Error
};

struct Expr {};

struct LabelNode {
  std::vector<Expr>* exprs;
};

#define CHECK_RESULT(expr) \
  do {                     \
    if ((expr) != Result::Ok) return Result::Error; \
  } while (0)

class BinaryReaderIR {
 public:
  Result TopLabelExpr(LabelNode** label, Expr** expr);
  Result TopLabel(LabelNode** label);
  Result GetLabelAt(LabelNode** label, int depth);
  void PrintError(const char* message);
};