#include <string>
#include <cstring>

#define key_bytes 32

namespace QPDF {
    class EncryptionData {
    public:
        int getLengthBytes() const;
    };
    std::string compute_encryption_key(std::string const&, EncryptionData const&);
}

namespace QUtil {
    unsigned char* unsigned_char_pointer(std::string&);
    unsigned char* unsigned_char_pointer(char*);
}

void pad_or_truncate_password_V4(const char*, char*);
void pad_short_parameter(std::string&, int);
void iterate_rc4(unsigned char*, int, unsigned char*, int, int, bool);