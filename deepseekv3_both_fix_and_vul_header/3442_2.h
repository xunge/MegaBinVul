#include <memory>
#include <vector>
#include <cassert>

template<typename T> class RefPtrWillBeMember {
public:
    RefPtrWillBeMember() = default;
    RefPtrWillBeMember(T* ptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    void operator=(std::nullptr_t) { m_ptr = nullptr; }
    bool operator!() const { return !m_ptr; }
private:
    T* m_ptr = nullptr;
};

class SpeechSynthesisUtterance {};
class PlatformSpeechSynthesizer {
public:
    void cancel() {}
};

class SpeechSynthesis {
public:
    void cancel();
    RefPtrWillBeMember<SpeechSynthesisUtterance> m_currentSpeechUtterance;
    std::vector<RefPtrWillBeMember<SpeechSynthesisUtterance>> m_utteranceQueue;
    PlatformSpeechSynthesizer* m_platformSpeechSynthesizer = nullptr;
};

#define ASSERT(expr) assert(expr)