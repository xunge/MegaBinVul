#include <string>
#include <atomic>

namespace ErrorCodes {
    enum Error {
        ProtocolError,
        AuthenticationFailed,
        BadValue
    };
}

class Status {
public:
    Status() = default;
    Status(ErrorCodes::Error code, const std::string& reason);
    static Status OK();
    bool isOK() const;
};

class UserName {
public:
    std::string getDB() const;
    std::string getUser() const;
};

class BSONObj {};

class AuthorizationSession {
public:
    void grantInternalAuthorization();
    Status addAndAuthorizeUser(const UserName& user);
};

class ClientBasic {
public:
    class Port {
    public:
        std::string getX509SubjectName() const;
    };
    static ClientBasic* getCurrent();
    Port* port() const;
    AuthorizationSession* getAuthorizationSession() const;
};

class SSLManager {
public:
    static SSLManager* getSSLManager();
    std::string getServerSubjectName() const;
};

class ServerGlobalParams {
public:
    enum ClusterAuthMode {
        ClusterAuthMode_undefined,
        ClusterAuthMode_keyFile
    };
    std::atomic<int> clusterAuthMode;
};

class CmdAuthenticate {
public:
    Status _authenticateX509(const UserName& user, const BSONObj& cmdObj);
private:
    SSLManager* getSSLManager() { return SSLManager::getSSLManager(); }
};

extern ServerGlobalParams serverGlobalParams;
extern bool _isX509AuthDisabled;
extern std::string _x509AuthenticationDisabledMessage;

void fassert(int, bool);