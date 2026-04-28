#include <string>

class Arg {
public:
    Arg& set(const std::string& name, const std::string& help);
    Arg& setSwitch(const std::string& name, const std::string& help);
    Arg& setCmd(const std::string& name, const std::string& help);
    Arg& operator=(const std::string& value);
};

Arg& arg();