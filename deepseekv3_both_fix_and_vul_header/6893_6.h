#include <map>
#include <limits>
#include <vector>
#include <string>
#include <cmath>
#include <functional>

typedef int64_t int64;

class uint256 {
public:
    std::string ToString() const;
    std::string substr(size_t pos, size_t len) const;
    bool operator<(const uint256& other) const { return false; }
};

class CTransaction;

class COutPoint {
public:
    uint256 hash;
    unsigned int n;
    bool operator<(const COutPoint& other) const {
        if (hash < other.hash) return true;
        if (other.hash < hash) return false;
        return n < other.n;
    }
};

class CTxIn {
public:
    COutPoint prevout;
};

class CInPoint {
public:
    CTransaction* ptx;
    unsigned int n;
};

class CTxIndex {};
class CDiskTxPos {
public:
    CDiskTxPos(int nFile, int nBlockPos, int nTxPos) {}
};
class CBlockIndex {};

struct MapPrevTx {
    std::map<COutPoint, CInPoint> mapOutPoints;
};

class CTransaction {
public:
    bool CheckTransaction();
    bool IsCoinBase();
    int DoS(int level, bool ret);
    bool IsStandard();
    uint256 GetHash();
    std::vector<CTxIn> vin;
    int64 nLockTime;
    bool FetchInputs(class CTxDB& txdb, std::map<uint256, class CTxIndex>& mapUnused, bool fBlock, bool fMiner, MapPrevTx& inputsRet, bool& fInvalid);
    bool AreInputsStandard(const MapPrevTx& mapInputs);
    int64 GetValueIn(const MapPrevTx& mapInputs);
    int64 GetValueOut();
    int64 GetMinFee(unsigned int nTxSize, bool fAllowFree, int nGranularity);
    bool IsNewerThan(const CTransaction& old);
    bool IsFinal();
    bool ConnectInputs(MapPrevTx inputs, std::map<uint256, class CTxIndex> mapUnused, CDiskTxPos pos, CBlockIndex* pindexBlock, bool fBlock, bool fMiner);
};

class CTxDB {
public:
    bool ContainsTx(const uint256& hash);
};

class CCriticalSection {
public:
    void Lock();
    void Unlock();
};

#define LOCK(cs) CCriticalSection critical_section_##cs; critical_section_##cs.Lock()

class CTxMemPool {
public:
    bool accept(CTxDB &txdb, CTransaction &tx, bool fCheckInputs, bool fLimitFree, bool *pfMissingInputs);
    bool accept(CTxDB &txdb, CTransaction &tx, bool fCheckInputs, bool *pfMissingInputs);
    void remove(const CTransaction &tx);
    void addUnchecked(const uint256 &hash, const CTransaction &tx);
    std::map<uint256, CTransaction> mapTx;
    std::map<COutPoint, CInPoint> mapNextTx;
    CCriticalSection cs;
};

extern bool fTestNet;
extern bool fDebug;
extern CBlockIndex* pindexBest;
extern int64 MIN_RELAY_TX_FEE;
extern int GMF_RELAY;
extern int SER_NETWORK;
extern int PROTOCOL_VERSION;

int64 GetTime();
int GetArg(const std::string& strArg, int nDefault);
bool IsFromMe(const CTransaction& tx);
bool error(const char* format, ...);
unsigned int GetSerializeSize(const CTransaction& tx, int serType, int version);
void EraseFromWallets(const uint256& hash);

// Add missing std:: prefix to map declarations
using std::map;