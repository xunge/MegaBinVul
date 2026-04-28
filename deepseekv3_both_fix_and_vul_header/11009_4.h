#include <stddef.h>

typedef struct Parse Parse;
typedef struct Expr Expr;
typedef struct CollSeq CollSeq;
typedef struct Vdbe Vdbe;
typedef unsigned char u8;

struct Parse {
    int nErr;
    Vdbe *pVdbe;
};

struct Expr {};
struct CollSeq {};
struct Vdbe {};

#define P4_COLLSEQ 0
#define sqlite3BinaryCompareCollSeq(pParse, pLeft, pRight) ((CollSeq*)0)
#define binaryCompareP5(pLeft, pRight, jumpIfNull) (0)
#define sqlite3VdbeAddOp4(pVdbe, opcode, in2, dest, in1, p4, type) (0)
#define sqlite3VdbeChangeP5(pVdbe, p5) (void)0