#include <stddef.h>

#define CHECK(condition) ((void)0)

class TtsMessageFilter {
public:
    void OnVoicesChanged();
    bool Valid();
    void OnInitializeVoiceList();
};

namespace BrowserThread {
    enum ID {
        UI,
        IO,
        FILE,
        FILE_USER_BLOCKING,
        PROCESS_LAUNCHER,
        CACHE,
        NUM_THREADS
    };
    bool CurrentlyOn(ID identifier);
}