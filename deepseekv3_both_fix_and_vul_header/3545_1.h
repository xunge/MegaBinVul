#include <vector>
#include <map>
#include <cstdlib>

struct Instruction {
    unsigned short code;
    unsigned int k;
    Instruction* next;
    Instruction* jt_ptr;
    Instruction* jf_ptr;
};

struct BasicBlock {
    std::vector<Instruction*> instructions;
};

typedef std::vector<Instruction*> Instructions;
typedef std::map<Instruction*, BasicBlock*> TargetsToBlocks;

#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_OP(code) ((code) & 0xf0)
#define BPF_JMP 0x05
#define BPF_RET 0x06
#define BPF_JA  0x00

#define CHECK(expr) if (!(expr)) abort()