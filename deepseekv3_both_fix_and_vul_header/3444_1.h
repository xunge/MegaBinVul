#include <stddef.h>

class SpeechSynthesisUtterance;
class ExceptionState {
public:
    void throwTypeError(const char* message);
};

template<typename T>
class Vector {
public:
    void append(T* item);
    size_t size() const;
};

class SpeechSynthesis {
public:
    void speak(SpeechSynthesisUtterance* utterance, ExceptionState& exceptionState);
private:
    Vector<SpeechSynthesisUtterance> m_utteranceQueue;
    void startSpeakingImmediately();
    void startSpeakingImmediately(SpeechSynthesisUtterance* utterance);
};