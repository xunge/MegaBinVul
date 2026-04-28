#include <string>
#include <cstring>

#define OU_key_bytes_V4 32
#define key_bytes 32

struct QPDF {
    struct EncryptionData {
        const unsigned char* getO() const;
        int getLengthBytes() const;
        int getR() const;
    };
};

namespace QUtil {
    unsigned char* unsigned_char_pointer(const std::string&);
    unsigned char* unsigned_char_pointer(const unsigned char*);
}

void compute_O_rc4_key(std::string&, std::string const&, QPDF::EncryptionData const&, unsigned char*);
void pad_short_parameter(std::string&, int);
void iterate_rc4(unsigned char*, int, unsigned char*, int, int, bool);
bool check_user_password(std::string const&, QPDF::EncryptionData const&);