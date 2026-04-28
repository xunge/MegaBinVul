#include <stddef.h>

struct SpeechUtterance;

struct PlatformSpeechSynthesizer {
    void resume();
};

class SpeechSynthesis {
public:
    SpeechUtterance* currentSpeechUtterance() const { return m_currentSpeechUtterance; }
    void resume();
    SpeechUtterance* m_currentSpeechUtterance;
    PlatformSpeechSynthesizer* m_platformSpeechSynthesizer;
};