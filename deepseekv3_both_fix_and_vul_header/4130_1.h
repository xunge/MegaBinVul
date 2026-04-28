#include <stdbool.h>

#define DCHECK_CURRENTLY_ON(thread) (true)
#define BrowserThread_UI 0

struct WebrtcAudioPrivateGetSinksFunction {
    bool RunAsync();
};

void InitDeviceIDSalt();
void GetOutputDeviceNames();
void InitResourceContext();