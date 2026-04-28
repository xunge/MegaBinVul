#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;

class uint256;
class CTxDB;

class Value {
public:
    Value() {}
    Value(const string& s) {}
    string get_str() const { return ""; }
};

class Array {
public:
    size_t size() const { return 0; }
    const Value& operator[](size_t) const { static Value v(""); return v; }
};

class CDataStream {
public:
    CDataStream(const vector<unsigned char>&, int, int) {}
    template<typename T> CDataStream& operator>>(T&) { return *this; }
};

class CTransaction {
public:
    uint256 GetHash() const;
    bool AcceptToMemoryPool(CTxDB&, bool, bool);
    bool AcceptToMemoryPool(CTxDB&);
};

class uint256 {
public:
    uint256() {}
    uint256(int) {}
    string GetHex() const { return ""; }
    bool operator!=(int) const { return false; }
};

class CTxDB {
public:
    CTxDB(const char*) {}
};

class CInv {
public:
    CInv(int, const uint256&) {}
};

enum RPCType { str_type };

template<typename T>
vector<T> list_of(const T& t) { return {t}; }

void RPCTypeCheck(const Array&, const vector<RPCType>&) {}
vector<unsigned char> ParseHex(const string&) { return {}; }
string JSONRPCError(int, const string&) { return ""; }
bool GetTransaction(const uint256&, CTransaction&, uint256&) { return false; }
void SyncWithWallets(const CTransaction&, void*, bool) {}
void RelayMessage(const CInv&, const CTransaction&) {}

const int SER_NETWORK = 0;
const int PROTOCOL_VERSION = 0;
const int MSG_TX = 0;