#include <nlohmann/json.hpp>

using json = nlohmann::json;

enum ValueType {
    NULL_TYPE
};

struct Extras {
    ValueType Type() const { return NULL_TYPE; }
};

struct Sampler {
    int magFilter = -1;
    int minFilter = -1;
    int wrapS = 0;
    int wrapT = 0;
    Extras extras;
};

void SerializeNumberProperty(const char* name, int value, json& o);
void SerializeValue(const char* name, const Extras& value, json& o);