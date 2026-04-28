#include <vector>
#include <cassert>
#include <cstdint>
#include <stdexcept>

#define TABLE_SIZE 65536
#define ThrowRDE(fmt, ...) throw std::runtime_error(fmt)

typedef uint16_t ushort16;

class TableLookUp {
private:
    int ntables;
    ushort16* tables;
    bool dither;
public:
    void setTable(int ntable, const std::vector<ushort16>& table);
};