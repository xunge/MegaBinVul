#include <vector>
#include <string>

enum class Result {
    Ok,
    Error
};

class BinaryReaderIR {
public:
    std::vector<std::string> label_stack_;
    void PrintError(const std::string& message);
    Result EndInitExpr();
};