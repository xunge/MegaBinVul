#include <string>
#include <memory>
#include <vector>
#include <cstdint>

typedef void* jobject;
typedef void* jstring;
typedef void* jclass;
typedef void* jmethodID;
typedef bool jboolean;
typedef int32_t jint;

#define JNI_TRUE true
#define JNI_FALSE false

struct JNIEnv {
    jobject NewLocalRef(jobject obj);
    void DeleteLocalRef(jobject obj);
    jstring NewStringUTF(const char*);
    jobject NewObject(jclass clazz, jmethodID methodID, ...);
    void CallVoidMethod(jobject obj, jmethodID methodID, ...);
    jboolean ExceptionCheck();
};

struct InputDeviceIdentifier {
    int32_t vendor;
    int32_t product;
    std::string descriptor;
};

struct MotionRange {
    int32_t axis;
    int32_t source;
    float min;
    float max;
    float flat;
    float fuzz;
    float resolution;
};

class KeyCharacterMap {};

class InputDeviceInfo {
public:
    using MotionRange = ::MotionRange;
    
    std::string getDisplayName() const;
    std::shared_ptr<KeyCharacterMap> getKeyCharacterMap() const;
    const InputDeviceIdentifier& getIdentifier() const;
    int32_t getId() const;
    bool hasMic() const;
    bool isExternal() const;
    int32_t getSources() const;
    int32_t getKeyboardType() const;
    bool hasVibrator() const;
    bool hasButtonUnderPad() const;
    bool hasSensor() const;
    bool hasBattery() const;
    int32_t getGeneration() const;
    int32_t getControllerNumber() const;
    const std::vector<MotionRange>& getMotionRanges() const;
};

template<typename T>
struct ScopedLocalRef {
    ScopedLocalRef(JNIEnv* env, T obj) : mEnv(env), mObj(obj) {}
    ~ScopedLocalRef() { if (mObj) mEnv->DeleteLocalRef(mObj); }
    T get() { return mObj; }
    JNIEnv* mEnv;
    T mObj;
};

struct InputDeviceClassInfo {
    jclass clazz;
    jmethodID ctor;
    jmethodID addMotionRange;
};

extern InputDeviceClassInfo gInputDeviceClassInfo;
extern jobject android_view_KeyCharacterMap_create(JNIEnv* env, int32_t deviceId, std::shared_ptr<KeyCharacterMap> kcm);