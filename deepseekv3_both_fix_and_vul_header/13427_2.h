#include <stdbool.h>

class Type;

class BinaryOperatorInst {
public:
    class Value* getLeftHandSide();
    class Value* getRightHandSide();
    void setType(Type ty);
};

class Value {
public:
    Type getType();
};

class Type {
public:
    static Type createNumber();
    static Type createBigInt();
    static Type createNoType();
    static Type unionTy(Type a, Type b);
    bool isNumberType() const;
    bool isBigIntType() const;
    bool canBeBigInt() const;
    bool isBigIntOrObject(const Type& ty) const;
};

bool isBigIntOrObject(const Type& ty);