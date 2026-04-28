#include <cstdint>
#include <mutex>

#define LOCK(m) std::lock_guard<std::mutex> lock(m)

class uint256 {};

struct indexed_transaction_set {
    struct const_iterator {
        const_iterator& operator*() { return *this; }
        bool operator==(const const_iterator&) const { return false; }
        uint64_t GetCountWithAncestors() const { return 0; }
        const_iterator* operator->() { return this; }
    };
    const_iterator find(const uint256&) const { return const_iterator(); }
    const_iterator end() const { return const_iterator(); }
};

class CTxMemPool {
public:
    bool CompareDepthAndScore(const uint256& hasha, const uint256& hashb, bool wtxid);
private:
    std::mutex cs;
    indexed_transaction_set mapTx;
    indexed_transaction_set::const_iterator get_iter_from_wtxid(const uint256&) const { return mapTx.end(); }
};

struct CompareTxMemPoolEntryByScore {
    bool operator()(const indexed_transaction_set::const_iterator&,
                    const indexed_transaction_set::const_iterator&) const { return false; }
};