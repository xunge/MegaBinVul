#include <string>
#include <vector>

class Csock {
public:
    std::string GetEncoding();
    void SetEncoding(const std::string&);
};

class CZNC {
private:
    unsigned int m_uiForceEncoding;
public:
    std::vector<Csock*> GetManager();
    void ForceEncoding();
};