#include <vector>
#include <string>
#include <cstdint>

enum jtokentype {
    JTOK_NONE,
    JTOK_ERR,
    JTOK_OBJ_OPEN,
    JTOK_OBJ_CLOSE,
    JTOK_ARR_OPEN,
    JTOK_ARR_CLOSE,
    JTOK_COLON,
    JTOK_COMMA,
    JTOK_KW_NULL,
    JTOK_KW_TRUE,
    JTOK_KW_FALSE,
    JTOK_NUMBER,
    JTOK_STRING
};

enum VType {
    VNULL,
    VOBJ,
    VARR,
    VNUM,
    VSTR,
    VBOOL
};

class UniValue {
public:
    UniValue() {}
    UniValue(VType t) : typ(t) {}
    UniValue(VType t, const std::string& val) : typ(t), value(val) {}
    
    VType getType() const { return typ; }
    void setObject() { typ = VOBJ; }
    void setArray() { typ = VARR; }
    void setBool(bool val) { typ = VBOOL; }
    void clear() {}
    bool expect(uint32_t mask) const { return false; }
    void setExpect(uint32_t mask) {}
    void clearExpect(uint32_t mask) {}
    bool jsonTokenIsValue(jtokentype tok) const { return false; }
    jtokentype getJsonToken(std::string& tokenVal, unsigned int& consumed, const char* raw, const char* end) { return JTOK_NONE; }
    bool read(const char *raw, size_t size);

    std::vector<UniValue> values;
    std::vector<std::string> keys;
    VType typ;
    std::string value;
};

const uint32_t VALUE = 1;
const uint32_t ARR_VALUE = 2;
const uint32_t OBJ_NAME = 4;
const uint32_t COLON = 8;
const uint32_t NOT_VALUE = 16;