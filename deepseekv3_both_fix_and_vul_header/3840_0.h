#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct HWVoiceOut HWVoiceOut;
typedef struct OSSVoiceOut OSSVoiceOut;

struct HWVoiceOut {
    size_t size_emul;
    size_t pos_emul;
    void *buf_emul;
};

struct OSSVoiceOut {
    int fd;
    int mmapped;
};

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static size_t oss_get_available_bytes(OSSVoiceOut *oss);
static void oss_logerr(int errnum, const char *fmt, ...);
static void *advance(void *buf, size_t pos);