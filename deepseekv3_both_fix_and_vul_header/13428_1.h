#include <stdbool.h>

typedef struct Type Type;
typedef struct Value Value;
typedef struct UnaryOperatorInst UnaryOperatorInst;

struct Type {
    bool isNumberType();
    bool isBigIntType();
    bool canBeBigInt();
    static Type createBigInt();
    static Type createNoType();
    static Type unionTy(Type, Type);
};

struct Value {
    Type getType();
};

struct UnaryOperatorInst {
    Value* getSingleOperand();
    void setType(Type);
};

bool isBigIntOrObject(Type);