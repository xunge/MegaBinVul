#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cassert>

#define DCHECK_LT(a, b) assert((a) < (b))

class HeaderTable {
private:
    uint32_t capacity_;
    uint32_t size_;
    uint32_t head_;
    std::vector<uint32_t> table_;
    std::map<std::string, std::vector<uint32_t>> names_;

    void evict(uint32_t count);
    uint32_t tail() const;

public:
    void setCapacity(uint32_t capacity);
};