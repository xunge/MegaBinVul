#include <string>
#include <cstring>

#define OU_key_bytes_V4 32
#define key_bytes 32

namespace QPDF {
    class EncryptionData {
    public:
        int getR() const;
        int getLengthBytes() const;
    };
}

namespace QUtil {
    unsigned char* unsigned_char_pointer(char*);
}

static void compute_O_rc4_key(std::string const&, std::string const&, QPDF::EncryptionData const&, unsigned char*);
static void pad_or_truncate_password_V4(std::string const&, char*);
static void pad_short_parameter(std::string&, int);
static void iterate_rc4(unsigned char*, int, unsigned char*, int, int, bool);