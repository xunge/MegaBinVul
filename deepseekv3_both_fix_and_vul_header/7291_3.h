#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

typedef int32_t OSStatus;
typedef void* AudioComponentInstance;

extern AudioComponentInstance au_rec_;
extern AudioComponentInstance au_play_;

int AudioOutputUnitStop(AudioComponentInstance inUnit);
int AudioComponentInstanceDispose(AudioComponentInstance inInstance);

class audio_io_osx {
public:
    static int32_t shutdown_audio_unit();
};

static inline void error(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}