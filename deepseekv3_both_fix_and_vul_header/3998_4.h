#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <memory>
#include <mutex>
#include <atomic>
#include <functional>
#include <optional>
#include <cstdint>
#include <sys/types.h>

using namespace std;

enum {
    NO_INIT = -1,
    INVALID_OPERATION = -2,
    PERMISSION_DENIED = -3,
    NO_ERROR = 0
};

typedef int status_t;
typedef int32_t audio_port_handle_t;

enum audio_source_t {
    AUDIO_SOURCE_FM_TUNER = 1998,
    AUDIO_SOURCE_REMOTE_SUBMIX = 1999,
    AUDIO_SOURCE_ECHO_REFERENCE = 2000
};

enum AppState {
    APP_STATE_TOP
};

struct String16 {
    String16(const char* str) {}
};

struct AttributionSource {
    int uid;
    optional<string> packageName;
    string toString() const { return ""; }
};

struct audio_attributes_t {
    audio_source_t source;
};

template<typename T>
class sp {
public:
    sp() = default;
    T* operator->() { return nullptr; }
};

template<typename K, typename V>
class KeyedVector {
public:
    ssize_t indexOfKey(const K& key) const { return 0; }
    V valueAt(size_t index) const { return V(); }
    size_t size() const { return 0; }
    K keyAt(size_t index) const { return K(); }
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class Status {
public:
    static Status binderStatusFromStatusT(status_t status) { return Status(); }
};

class AutoCallerClear {};

class AudioPolicyManager {
public:
    status_t startInput(audio_port_handle_t) { return NO_ERROR; }
};

class AudioPolicyService {
public:
    Status startInput(int32_t portIdAidl);
private:
    AudioPolicyManager* mAudioPolicyManager = nullptr;
    Mutex mLock;
    KeyedVector<audio_port_handle_t, sp<struct AudioRecordClient>> mAudioRecordClients;
};

template<typename T>
T VALUE_OR_RETURN_BINDER_STATUS(T&& u) {
    return u;
}

status_t aidl2legacy_int32_t_audio_port_handle_t(int32_t) { return 0; }
bool startRecording(const AttributionSource&, String16, audio_source_t) { return false; }
void finishRecording(const AttributionSource&, audio_source_t) {}
void setAppState_l(const sp<struct AudioRecordClient>&, AppState) {}
void updateUidStates_l() {}
string toString(audio_source_t) { return ""; }
string getDeviceTypeStrForPortId(audio_port_handle_t) { return ""; }
long systemTime() { return 0; }
void ALOGE(const char*, ...) {}
void ALOGW_IF(bool, const char*, ...) {}

struct AudioRecordClient {
    int session;
    bool silenced;
    bool active;
    long startTimeNs;
    audio_attributes_t attributes;
    AttributionSource attributionSource;
    audio_port_handle_t deviceId;
};

struct mediametrics {
    struct Item {
        static Item* create(const char*) { return nullptr; }
        void setInt32(const char*, int32_t) {}
        void setCString(const char*, const char*) {}
        void selfrecord() {}
    };
};

inline Status binderStatusFromStatusT(status_t status) {
    return Status::binderStatusFromStatusT(status);
}