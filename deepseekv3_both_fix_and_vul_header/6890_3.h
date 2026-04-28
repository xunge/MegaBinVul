#include <stdbool.h>

class CTransaction;

class CTxDB {
public:
    // 空定义，仅用于编译
};

class CTxMemPool {
public:
    bool accept(CTxDB& txdb, CTransaction& tx, bool fCheckInputs, bool fLimitFree, bool* pfMissingInputs);
    bool accept(CTxDB& txdb, CTransaction& tx, bool fCheckInputs, bool* pfMissingInputs);
};

extern CTxMemPool mempool;

class CTransaction {
public:
    bool AcceptToMemoryPool(CTxDB& txdb, bool fCheckInputs, bool fLimitFree, bool* pfMissingInputs);
    bool AcceptToMemoryPool(CTxDB& txdb, bool fCheckInputs, bool* pfMissingInputs);
};