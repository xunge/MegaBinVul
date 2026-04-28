#include <stddef.h>

class WebrtcAudioPrivateFunction {
public:
    WebrtcAudioPrivateFunction();
    explicit WebrtcAudioPrivateFunction(void* context);

private:
    void* resource_context_;
};