#include <cassert>
#include <ctime>

class PlatformSpeechSynthesizer {
public:
    void speak(void* utterance);
};

class SpeechSynthesisUtterance {
public:
    void setStartTime(double time);
    void* platformUtterance();
};

class SpeechSynthesis {
public:
    SpeechSynthesisUtterance* currentSpeechUtterance();
    double monotonicallyIncreasingTime();
    void startSpeakingImmediately();
    void startSpeakingImmediately(SpeechSynthesisUtterance* utterance);

    bool m_isPaused;
    SpeechSynthesisUtterance* m_currentSpeechUtterance;
    PlatformSpeechSynthesizer* m_platformSpeechSynthesizer;
};

#define ASSERT(expr) assert(expr)