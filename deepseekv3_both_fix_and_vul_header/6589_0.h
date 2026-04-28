#include <string.h>

class String {
public:
    size_t size() const;
    const char* c_str() const;
};

class HdrDecoder {
    String m_signature;
    String m_signature_alt;
public:
    bool checkSignature(const String& signature) const;
};