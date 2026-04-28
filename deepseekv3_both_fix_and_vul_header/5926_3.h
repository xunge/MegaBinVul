#include <string>

struct output_handle {
    output_handle& newline();
    output_handle& operator<<(const std::string&);
};

struct stap_operator {
    output_handle* op;
    output_handle& newline() { return op->newline(); }
};

class systemtap_session {
public:
    stap_operator* op;
};

template<typename T>
std::string lex_cast_qstring(const T&);

const char* _(const char*);