#include <stdbool.h>

struct IPC {
    struct Message {
        int type() const;
        static const int ID;
    };
};

struct PpapiMsg_GetSitesWithData {
    static const int ID;
};
struct PpapiMsg_ClearSiteData {
    static const int ID;
};
struct PpapiMsg_DeauthorizeContentLicenses {
    static const int ID;
};
struct PpapiMsg_GetPermissionSettings {
    static const int ID;
};
struct PpapiMsg_SetDefaultPermission {
    static const int ID;
};
struct PpapiMsg_SetSitePermission {
    static const int ID;
};

namespace base {
    namespace debug {
        void DumpWithoutCrashing();
    }
}

class BrokerSideDispatcher {
public:
    bool OnMessageReceived(const IPC::Message& msg);
};

class BrokerProcessDispatcher : public BrokerSideDispatcher {
private:
    bool peer_is_browser_;
public:
    bool OnMessageReceived(const IPC::Message& msg);
    void OnGetSitesWithData();
    void OnClearSiteData();
    void OnDeauthorizeContentLicenses();
    void OnGetPermissionSettings();
    void OnSetDefaultPermission();
    void OnSetSitePermission();
};

#define IPC_BEGIN_MESSAGE_MAP(className, msg)
#define IPC_MESSAGE_HANDLER(message, function)
#define IPC_MESSAGE_UNHANDLED(expr)
#define IPC_END_MESSAGE_MAP()