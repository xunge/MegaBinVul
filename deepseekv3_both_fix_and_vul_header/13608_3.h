#include <string>
#include <memory>

struct ParserState {};

struct SimpleSelector {
    struct ToStringOptions {
        int nested;
        int precision;
    };
    std::string to_string(ToStringOptions) const { return ""; }
    virtual ~SimpleSelector() = default;
};

using SimpleSelectorObj = std::shared_ptr<SimpleSelector>;

struct Type_Selector : public SimpleSelector {
    Type_Selector(ParserState, const char*) {}
};

struct CompoundSelector {
    ParserState pstate;
    bool hasRealParent_;
    bool hasPostLineBreak_;

    CompoundSelector(ParserState p) : pstate(p), hasRealParent_(false), hasPostLineBreak_(false) {}
    void hasRealParent(bool val) { hasRealParent_ = val; }
    bool hasRealParent() const { return hasRealParent_; }
    bool empty() const { return false; }
    bool hasPostLineBreak() const { return hasPostLineBreak_; }
    void hasPostLineBreak(bool val) { hasPostLineBreak_ = val; }
    size_t length() const { return 0; }
    SimpleSelectorObj operator[](size_t) const { return nullptr; }
    void append(SimpleSelectorObj) {}
    SimpleSelectorObj last() const { return nullptr; }
};

using CompoundSelectorObj = std::shared_ptr<CompoundSelector>;

#define SASS_MEMORY_NEW(Type, ...) std::make_shared<Type>(__VA_ARGS__)

class Parser {
public:
    ParserState pstate;
    bool allow_parent;
    const char* lexed;

    CompoundSelectorObj parseCompoundSelector();
    SimpleSelectorObj parse_simple_selector() { return nullptr; }
    void error(const std::string&, const ParserState&) {}
    void error(const std::string& msg) { error(msg, pstate); }
    void advanceToNextToken() {}
    bool peek_newline() { return false; }

    template<typename T> bool lex() { return false; }
    template<typename T> bool lex(bool) { return false; }
    template<typename T> bool match() { return false; }
    template<typename T> bool peek() { return false; }
    template<typename T> bool peek_css() { return false; }
};

struct block_comment {};
struct identifier {};
struct spaces {};
struct end_of_file {};
struct selector_combinator_ops {};
struct complex_selector_delims {};

template<char c> struct exactly {};
struct re_functional {};
struct re_type_selector {};
template<typename T> struct class_char {};
template<typename... T> struct alternatives {};

constexpr int NESTED = 0;