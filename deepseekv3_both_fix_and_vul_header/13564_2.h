#include <cstddef>
#include <string>

struct Value;

struct Key {
    static const char* key();
    static std::string Encode(const Value& value);
};

struct Value {};

size_t EncodedSizeOfKey(const Key&, const Value&);
void AddToSummary(const char*, size_t);