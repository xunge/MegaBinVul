#include <string>

struct Sampler {
    std::string extensions;
    std::string extras;
    int magFilter;
    int minFilter;
    std::string name;
    int wrapS;
    int wrapT;

    bool operator==(const Sampler& other) const;
};