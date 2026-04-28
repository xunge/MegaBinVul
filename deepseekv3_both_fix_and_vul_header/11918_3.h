#include <memory>

template<char C> struct exactly {};
struct css_whitespace {};

struct Supports_Condition_Obj {
    bool isNull() const;
    operator bool() const;
    bool operator!=(int) const;
    Supports_Condition_Obj();
};

class Parser {
public:
    Supports_Condition_Obj parse_supports_interpolation();
    Supports_Condition_Obj parse_supports_condition(bool top_level = true);
    Supports_Condition_Obj parse_supports_declaration();
    Supports_Condition_Obj parse_supports_condition_in_parens(bool parens_required);
    Supports_Condition_Obj parse_supports_condition_in_parens();
    void error(const char* msg);
    void css_error(const char* msg1, const char* msg2, const char* msg3, bool trim);
    template <typename T> bool lex();
};