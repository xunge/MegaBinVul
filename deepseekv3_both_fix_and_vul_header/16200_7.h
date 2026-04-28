#include <string>
#include <iostream>

#define SERVICE_WIN32_OWN_PROCESS 0x00000010
#define SERVICE_AUTO_START 0x00000002
#define SERVICE_ERROR_NORMAL 0x00000001
#define SERVICE_ALL_ACCESS 0x000F01FF
#define ERROR_SERVICE_EXISTS 1073
#define SERVICE_CONFIG_FAILURE_ACTIONS 2
#define SC_ACTION_RESTART 1

typedef struct _SC_ACTION {
    int Type;
    unsigned long Delay;
} SC_ACTION;

typedef struct _SERVICE_FAILURE_ACTIONS {
    unsigned long dwResetPeriod;
    const char* lpRebootMsg;
    const char* lpCommand;
    SC_ACTION* lpsaActions;
    unsigned long cActions;
} SERVICE_FAILURE_ACTIONS;

class QLatin1Char {
public:
    QLatin1Char(char) {}
    operator char() const { return '\0'; }
};

class QString {
public:
    QString() {}
    QString(const char*) {}
    QString(const QString&) {}
    QString replace(char, const QString&) { return *this; }
    QString arg(const QString&) { return *this; }
    const char* toUtf8() const { return ""; }
};

class WindowsCoreFunctions {
public:
    static const wchar_t* toConstWCharArray(const QString&) { return L""; }
};

void* CreateService(void*, const wchar_t*, const wchar_t*, unsigned long, unsigned long, 
                   unsigned long, unsigned long, const wchar_t*, void*, void*, const wchar_t*, void*, void*) { return nullptr; }
unsigned long GetLastError() { return 0; }
bool ChangeServiceConfig2(void*, unsigned long, void*) { return true; }

class WindowsServiceControl {
public:
    void* m_serviceHandle;
    void* m_serviceManager;
    QString m_name;
    bool install(const QString&, const QString&);
};

QString QStringLiteral(const char*) { return QString(); }
const char* qUtf8Printable(const QString& s) { return s.toUtf8(); }
QString tr(const char*) { return QString(); }

class VStream {
public:
    VStream& operator<<(const char*) { return *this; }
};

VStream vCritical() { return VStream(); }
VStream vInfo() { return VStream(); }