#include <stdbool.h>
#include <string.h>
#include <cstdlib>

class QString {
public:
    QString(const char* str = "") : data(strdup(str)) {}
    ~QString() { free(data); }
    bool isEmpty() const { return !data || !*data; }
    const char* toStdString() const { return data; }
    bool operator==(const char* str) const { return strcmp(data, str) == 0; }
    char* data;
};

class PamBackend {
public:
    bool start(const QString &user);
    
private:
    bool m_greeter;
    bool m_autologin;
    class App* m_app;
    class Pam* m_pam;
};

class App {
public:
    class Session* session();
    void error(const QString& errorString, int errorType);
};

class Session {
public:
    QString path();
};

class Pam {
public:
    bool start(const QString& service, const QString& user);
    QString errorString();
};

namespace Auth {
    const int ERROR_INTERNAL = 0;
}