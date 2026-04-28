#include <vector>
#include <string>
#include <cstdint>

template<typename T>
class StatusOr {
public:
    StatusOr(T value) : ok_(true) {}
    StatusOr(const std::string& msg) : ok_(false) {}
    bool ok() const { return ok_; }
private:
    bool ok_;
};

class Attribute {
public:
    template<typename T>
    operator T() const { return T(); }
    template<typename T>
    T dyn_cast() const { return T(); }
    template<typename T>
    T dyn_cast_or_null() const { return T(); }
};

class Type {};

class TypeAttr : public Attribute {
public:
    Type getValue() const { return Type(); }
    operator bool() const { return true; }
};

class ArrayAttr : public Attribute {
public:
    size_t size() const { return 0; }
    class iterator {
    public:
        Attribute operator*() const { return Attribute(); }
        iterator& operator++() { return *this; }
        bool operator!=(const iterator&) const { return false; }
    };
    iterator begin() const { return iterator(); }
    iterator end() const { return iterator(); }
    operator bool() const { return true; }
};

class IntegerAttr : public Attribute {
public:
    const IntegerAttr& getValue() const { return *this; }
    uint64_t getZExtValue() const { return 0; }
    operator bool() const { return true; }
};

class NamedAttrList {
public:
    Attribute get(const std::string& name) const { return Attribute(); }
};

enum DataType {
    DT_INVALID
};

class OpDef {
public:
    class ArgDef {
    public:
        const std::string& type_list_attr() const { static std::string s; return s; }
        const std::string& number_attr() const { static std::string s; return s; }
        const std::string& type_attr() const { static std::string s; return s; }
        const std::string& name() const { static std::string s; return s; }
        DataType type() const { return DT_INVALID; }
    };
};

class UnrankedTensorType {
public:
    static Type get(Type type) { return Type(); }
};

template<typename T>
class SmallVectorImpl {
public:
    void push_back(const T& value) {}
    void append(size_t count, const T& value) {}
};

class GraphDefImporter {
public:
    void* b_;
    StatusOr<unsigned> ArgNumType(const NamedAttrList& attrs, const OpDef::ArgDef& arg_def, SmallVectorImpl<Type>& types);
};

#define TF_RETURN_IF_ERROR(expr) do { auto _status = (expr); if (!_status.ok()) return _status; } while(0)

StatusOr<unsigned> InvalidArgument(const std::string& msg1, const std::string& msg2, const std::string& msg3) {
    return StatusOr<unsigned>(msg1 + msg2 + msg3);
}

StatusOr<unsigned> NotFound(const std::string& msg1, const std::string& msg2) {
    return StatusOr<unsigned>(msg1 + msg2);
}

StatusOr<unsigned> ConvertDataType(DataType type, void* b, Type* dtype) {
    return StatusOr<unsigned>(0);
}