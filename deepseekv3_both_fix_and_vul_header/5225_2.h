#include <string>
#include <vector>

class CString {
public:
    operator std::string() const;
};
class CZNC {
public:
    static CZNC& Get();
    std::string FixupEncoding(const CString& s);
};
class CClient {
public:
    void SetEncoding(const std::string& s);
};
class CUser {
    std::string m_sClientEncoding;
    std::vector<CClient*> GetAllClients();
    void SetClientEncoding(const CString& s);
};