#include <sys/types.h>
#include <vector>
#include <string>
#include <cstdint>

#define VALUE_OR_FATAL(x) (x)
#define ALOGD(...)

struct String16 {};

template<typename T>
class Vector {
public:
    bool isEmpty() const { return true; }
};

struct audio_attributes_t {
    int usage;
    int flags;
};

enum audio_stream_type_t {
    AUDIO_STREAM_ENFORCED_AUDIBLE
};

#define AUDIO_FLAG_BYPASS_INTERRUPTION_POLICY 0x1

struct AttributionSourceState {
    int32_t uid;
};

template<typename T>
class sp {
public:
    sp(T*) {}
};

namespace android {

class AudioFlinger {
public:
    class PlaybackThread {
    public:
        class OpPlayAudioMonitor {
        public:
            static sp<OpPlayAudioMonitor> createIfNeeded(
                const AttributionSourceState&, const audio_attributes_t&, int, audio_stream_type_t);
            OpPlayAudioMonitor(const AttributionSourceState&, int, int);
        };
    };

    static AttributionSourceState checkAttributionSourcePackage(const AttributionSourceState&);
};

uid_t aidl2legacy_int32_t_uid_t(int32_t);
void getPackagesForUid(uid_t, Vector<String16>&);
bool isServiceUid(uid_t);

} // namespace android

using namespace android;