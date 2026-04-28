#include <string>
#include <cstring>

#define key_bytes 32

class QPDF {
public:
    class EncryptionData {
    public:
        std::string getId1() const;
        int getLengthBytes() const;
    };
    static std::string compute_encryption_key(std::string const&, EncryptionData const&);
};

class MD5 {
public:
    typedef unsigned char Digest[16];
    void encodeDataIncrementally(const char*, size_t);
    void digest(Digest&);
};

class QUtil {
public:
    static unsigned char* unsigned_char_pointer(std::string const&);
};

std::string pad_or_truncate_password_V4(std::string const&);
void pad_short_parameter(std::string&, int);
void iterate_rc4(MD5::Digest, size_t, unsigned char*, int, int, bool);