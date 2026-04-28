#include <string>
#include <set>
#include <stdexcept>
#include <map>

enum encryption_method_e {
    e_none,
    e_rc4,
    e_aes,
    e_aesv3,
    e_unknown
};

class QPDFObjectHandle {
public:
    bool isArray();
    int getArrayNItems();
    QPDFObjectHandle getArrayItem(int);
    bool isString();
    std::string getStringValue();
    bool isDictionary();
    bool isName();
    std::string getName();
    bool isNull();
    bool isInteger();
    int getIntValue();
    bool isBool();
    bool getBoolValue();
    bool hasKey(std::string);
    QPDFObjectHandle getKey(std::string);
    std::set<std::string> getKeys();
};

class QPDF {
private:
    struct Members {
        bool encryption_initialized;
        bool encrypted;
        QPDFObjectHandle trailer;
        std::string last_object_description;
        int encryption_V;
        int encryption_R;
        bool encrypt_metadata;
        std::map<std::string, encryption_method_e> crypt_filters;
        encryption_method_e cf_stream;
        encryption_method_e cf_string;
        encryption_method_e cf_file;
        std::string user_password;
        std::string provided_password;
        std::string encryption_key;
        struct File {
            std::string getName();
            long getLastOffset();
        } *file;
    } *m;
public:
    void initializeEncryption();
};

struct QPDFExc {
    QPDFExc(int, std::string, std::string, long, std::string);
};

class QUtil {
public:
    static std::string int_to_string(int);
};

struct EncryptionData {
    EncryptionData(int, int, int, unsigned int, std::string, std::string, 
                  std::string, std::string, std::string, std::string, bool);
};

class QTC {
public:
    static void TC(const char*, const char*);
};

enum qpdf_error_code_e {
    qpdf_e_damaged_pdf,
    qpdf_e_unsupported,
    qpdf_e_password
};

void warn(QPDFExc);
void pad_short_parameter(std::string&, size_t);
bool check_owner_password(std::string&, std::string&, EncryptionData&);
bool check_user_password(std::string&, EncryptionData&);
std::string compute_encryption_key(std::string&, EncryptionData&);
std::string recover_encryption_key_with_password(std::string&, EncryptionData&, bool&);
encryption_method_e interpretCF(QPDFObjectHandle);

const size_t key_bytes = 32;
const size_t OU_key_bytes_V5 = 48;
const size_t OUE_key_bytes_V5 = 32;
const size_t Perms_key_bytes_V5 = 16;