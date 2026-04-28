#include <stddef.h>
#include <vector>

class Visitor {
public:
    void trace(void* obj);
};

class AudioContext {
public:
    class AutoLocker {
    public:
        AutoLocker(AudioContext* context);
    };
};

class AudioSummingJunction {
public:
    void trace(Visitor* visitor);
protected:
    AudioContext* m_context;
    std::vector<void*> m_renderingOutputs;
};