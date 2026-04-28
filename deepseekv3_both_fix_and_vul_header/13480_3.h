#include <string_view>

class WastLexer {
public:
    std::string_view GetText(size_t offset);
private:
    const char* token_start_;
    const char* cursor_;
    const char* buffer_end_;
};