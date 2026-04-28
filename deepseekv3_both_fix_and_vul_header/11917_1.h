#include <memory>

template <typename T>
void lex();

struct css_whitespace;

class Supports_Condition_Obj {
public:
    Supports_Condition_Obj() = default;
    operator bool() const { return false; }
};

class Parser {
public:
    Supports_Condition_Obj parse_supports_condition(bool top_level);
    Supports_Condition_Obj parse_supports_condition();
    Supports_Condition_Obj parse_supports_negation();
    Supports_Condition_Obj parse_supports_operator(bool top_level);
    Supports_Condition_Obj parse_supports_operator();
    Supports_Condition_Obj parse_supports_interpolation();
};