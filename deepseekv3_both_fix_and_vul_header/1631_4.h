#include <stdint.h>

struct Builder {};

struct Type {
    template<typename T> T dyn_cast();
    template<typename T> T dyn_cast_or_null();
    operator bool() const { return true; }
};

struct TypeAttr {
    Type getValue();
    static TypeAttr get(Type);
};

struct ShapedType {
    int64_t* getShape();
    Type getElementType();
    operator bool() const { return true; }
};

struct QuantizedType {
    Type castFromExpressedType(Type);
    template<typename T> T dyn_cast();
    template<typename T> T dyn_cast_or_null();
    operator bool() const { return true; }
    QuantizedType& operator=(QuantizedType* other) { return *this; }
};

struct UniformQuantizedPerAxisType {
    operator bool() const { return true; }
    operator UniformQuantizedPerAxisType*() { return this; }
};

QuantizedType* ResetAxisAndBroadcast(const int64_t* shape,
    UniformQuantizedPerAxisType* per_axis, Type target, int axis);

namespace quant {
    typedef QuantizedType QuantizedType;
    typedef UniformQuantizedPerAxisType UniformQuantizedPerAxisType;
}