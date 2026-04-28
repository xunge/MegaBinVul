#include <stddef.h>

struct ScriptForbiddenScope {
    ScriptForbiddenScope() {}
    ~ScriptForbiddenScope() {}
};

class FrameLoader {
public:
    class Client {
    public:
        void documentElementAvailable();
    };
    
    Client* client();
    void dispatchDocumentElementAvailable();
};