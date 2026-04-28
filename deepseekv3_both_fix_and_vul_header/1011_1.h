#include <string>

class Metadata {
public:
    static bool setString(const std::string&, const std::string&);
};

class ItemStackMetadata {
public:
    bool setString(const std::string &name, const std::string &var);
    void updateToolCapabilities();
    void sanitize_string(std::string &str);
};

static const std::string TOOLCAP_KEY;