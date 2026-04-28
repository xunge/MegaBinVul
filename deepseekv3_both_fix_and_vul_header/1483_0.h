#include <string>
#include <map>

#define TINYGLTF_TEXTURE_WRAP_REPEAT 10497

struct Sampler {
    std::string name;
    int minFilter;
    int magFilter;
    int wrapS;
    int wrapT;
    std::map<std::string, std::string> extensions;
    std::map<std::string, std::string> extras;
    std::string extensions_json_string;
    std::string extras_json_string;
};

using json = std::map<std::string, void*>;
using json_const_iterator = std::map<std::string, void*>::const_iterator;

bool ParseStringProperty(std::string*, std::string*, const json&, const char*, bool);
bool ParseIntegerProperty(int*, std::string*, const json&, const char*, bool);
bool ParseExtensionsProperty(std::map<std::string, std::string>*, std::string*, const json&);
bool ParseExtrasProperty(std::map<std::string, std::string>*, const json&);
bool FindMember(const json&, const char*, json_const_iterator&);
std::string JsonToString(const void*);
void* GetValue(json_const_iterator);