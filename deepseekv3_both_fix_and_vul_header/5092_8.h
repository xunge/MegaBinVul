#include <string>
#include <memory>
#include <vector>
#include <map>
#include <stdexcept>

using Index = size_t;

enum class ExternalKind { Invalid, Function, Memory, Table, Global };
enum class Type { i32, i64, f32, f64 };

struct Element {
    bool isList() const;
    bool isStr() const;
    bool quoted() const;
    bool dollared() const;
    std::string str() const;
    size_t size() const;
    Element& operator[](size_t);
    Element* operator->();
    Element& operator*();
};

struct Name {
    Name();
    Name(const std::string&);
    bool is() const;
    bool operator<(const Name&) const;
};

struct FunctionType {
    std::vector<Type> params;
    Type result;
    Name name;
};

struct Function {
    Name name;
    std::string module;
    std::string base;
    Name type;
    Type result;
};

struct Global {
    Name name;
    std::string module;
    std::string base;
    Type type;
    bool mutable_;
};

struct Table {
    std::string module;
    std::string base;
    size_t initial;
    size_t max;
    bool exists;
    static const size_t kUnlimitedSize;
};

struct Memory {
    std::string module;
    std::string base;
    bool exists;
    bool shared;
};

struct Wasm {
    Memory memory;
    Table table;
    FunctionType* getFunctionTypeOrNull(const Name&);
    FunctionType* getFunctionType(const Name&);
    void addFunction(Function*);
    void addGlobal(Global*);
};

struct ParseException : public std::runtime_error {
    ParseException(const std::string&);
};

struct IString {
    IString(const std::string&);
    bool operator==(const IString&) const;
    bool operator!=(const IString&) const;
    bool operator==(const std::string&) const;
    bool operator!=(const std::string&) const;
    std::string str() const;
    operator Name() const;
};

inline bool operator==(const std::string& lhs, const IString& rhs) {
    return rhs == lhs;
}

inline bool operator!=(const std::string& lhs, const IString& rhs) {
    return !(rhs == lhs);
}

struct SExpressionWasmBuilder {
    Wasm wasm;
    size_t functionCounter;
    size_t globalCounter;
    std::vector<Name> functionNames;
    std::vector<Name> globalNames;
    std::map<Name, Type> functionTypes;

    void parseImport(Element& s);
    Type stringToType(const std::string&);
    void parseMemoryLimits(Element&, size_t);
    size_t getCheckedAddress(Element&, const std::string&);
    FunctionType* ensureFunctionType(const std::string&, Wasm*);
    std::string getSig(FunctionType*);
};

namespace FunctionTypeUtils {
    void fillFunction(Function*, FunctionType*);
}

const IString FUNC{"func"};
const IString MEMORY{"memory"};
const IString TABLE{"table"};
const IString GLOBAL{"global"};
const IString PARAM{"param"};
const IString RESULT{"result"};
const IString TYPE{"type"};
const IString MUT{"mut"};

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}