#include <string>
#include <vector>
#include <iostream>

struct Name {
    bool equals(const std::string&) const;
    std::string str;
};

struct BinaryConsts {
    struct UserSections {
        static const std::string Name;
        static const std::string Linking;
    };
};

struct UserSection {
    std::string name;
    std::vector<int8_t> data;
};

struct Wasm {
    std::vector<UserSection> userSections;
};

class WasmBinaryBuilder {
public:
    void readUserSection(size_t payloadLen);
private:
    size_t pos;
    Name getInlineString();
    void throwError(const std::string&);
    void readNames(size_t);
    int8_t getInt8();
    Wasm wasm;
};