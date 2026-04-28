#include <string>
#include <map>

struct Accessor {
    struct {
        bool isSparse;
        int count;
        struct {
            int bufferView;
            int byteOffset;
            int componentType;
        } indices;
        struct {
            int bufferView;
            int byteOffset;
        } values;
    } sparse;
};

using json = std::map<std::string, std::string>;
using json_const_iterator = json::const_iterator;

bool ParseIntegerProperty(int* out, std::string* err, const json& obj, const char* prop, bool required, const char* context = "");
bool FindMember(const json& obj, const char* member, json_const_iterator& it);
const json& GetValue(const json_const_iterator& it);