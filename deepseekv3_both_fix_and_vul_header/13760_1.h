#include <cstdint>
#include <string>
#include <utility>

enum class FieldType {
    True,
    False,
    Int8,
    Int16,
    Int32,
    Int64,
    Double,
    Float,
    Binary,
    List,
    Struct,
    Stop,
    Set,
    Map
};

class CarbonProtocolReader {
public:
    void skip(const FieldType ft);
    template<typename T> void readRaw();
    void skipLinearContainer();
    void skipKVContainer();
    void readStructBegin();
    void readStructEnd();
    std::pair<FieldType, int16_t> readFieldHeader();
};