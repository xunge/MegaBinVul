#include <cstddef>
#include <vector>
#include <memory>

struct Array {
    static Array attach(void*);
    size_t size() const;
    bool empty() const;
};

struct PackedArray {
    static void* MakeReserve(size_t);
};

struct Variant {};
struct VarEnv {
    VarEnv* getOrCreateVarEnv();
};
struct PointerSet {};
struct g_context {
    static VarEnv* getOrCreateVarEnv();
};

extern g_context* g_context;

#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)

Array __SystemLib_compact_sl(const Variant&, const Array&);

void compact(PointerSet&, VarEnv*, Array&, const Variant&);
void compact(PointerSet&, VarEnv*, Array&, const Array&);
void compact(VarEnv*, Array&, const Variant&);
void compact(VarEnv*, Array&, const Array&);