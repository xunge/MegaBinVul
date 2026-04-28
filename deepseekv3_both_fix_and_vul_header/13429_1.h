#include <stdbool.h>

class Type {
public:
    static Type createBoolean();
    static Type createInt32();
    static Type createUint32();
    static Type createString();
    static Type createNumber();
    static Type createBigInt();
    static Type createNoType();
    static Type unionTy(Type, Type);
    
    bool isStringType();
    bool isNumberType();
    bool isBigIntType();
    bool canBeString();
    bool canBeBigInt();
};

class BinaryOperatorInst {
public:
    enum class OpKind {
        EqualKind,
        NotEqualKind,
        StrictlyEqualKind,
        StrictlyNotEqualKind,
        LessThanKind,
        LessThanOrEqualKind,
        GreaterThanKind,
        GreaterThanOrEqualKind,
        InKind,
        InstanceOfKind,
        DivideKind,
        MultiplyKind,
        SubtractKind,
        LeftShiftKind,
        RightShiftKind,
        ModuloKind,
        UnsignedRightShiftKind,
        AddKind,
        AndKind,
        OrKind,
        XorKind
    };
    
    OpKind getOperatorKind();
    void setType(Type type);
    class Value *getLeftHandSide();
    class Value *getRightHandSide();
};

class Value {
public:
    Type getType();
};

bool inferBinaryArith(BinaryOperatorInst *, Type = Type());
bool inferBinaryBitwise(BinaryOperatorInst *);
bool isSideEffectFree(Type);
bool isBigIntOrObject(Type);