#include <cstring>
#include <vector>
#include <stdexcept>

enum class PdfKeyLength;
enum class PdfEncryptAlgorithm;

enum class PdfErrorCode {
    InvalidEncryptionDict
};

#define PODOFO_RAISE_ERROR_INFO(code, msg) throw std::runtime_error(msg)

class PdfString {
public:
    const std::vector<char>& GetRawData() const;
};

struct PdfPermissions {};

class PdfEncryptRC4 {
public:
    PdfEncryptRC4(PdfString oValue, PdfString uValue, PdfPermissions pValue, int rValue,
        PdfEncryptAlgorithm algorithm, int length, bool encryptMetadata);
private:
    PdfPermissions m_pValue;
    int m_rValue;
    PdfEncryptAlgorithm m_Algorithm;
    PdfKeyLength m_eKeyLength;
    int m_keyLength;
    bool m_EncryptMetadata;
    char m_oValue[32];
    char m_uValue[32];
    char m_rc4key[16];
    char m_rc4last[256];
    char m_encryptionKey[32];
};