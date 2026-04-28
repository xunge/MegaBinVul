#include <stdbool.h>

struct SpeechUtterance;

struct SpeechSynthesis {
    struct SpeechUtterance* m_currentSpeechUtterance;
    struct SpeechUtterance* currentSpeechUtterance() const;
    bool speaking() const;
};