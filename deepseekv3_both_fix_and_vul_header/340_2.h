#include <cstdint>
#include <stdexcept>

enum DataLocId {
    valueData,
    directoryData,
    invalidDataLocId
};

class Error {
public:
    Error(int code) {}
};

const int kerCorruptedMetadata = 0;

class CiffComponent {
public:
    DataLocId dataLocation(uint16_t tag);
};