#include <stdbool.h>
#include <stddef.h>

typedef struct SpeechSynthesisUtterance SpeechSynthesisUtterance;
struct String { String(); };
template<typename T> struct RefPtrWillBeMember { 
    T* get(); 
    bool operator==(const T*) const;
};

enum EventTypeNames { error, end };

struct SpeechSynthesis {
    SpeechSynthesisUtterance* m_currentSpeechUtterance;
    struct {
        RefPtrWillBeMember<SpeechSynthesisUtterance> first();
        void removeFirst();
        bool isEmpty();
        size_t size();
    } m_utteranceQueue;
    
    SpeechSynthesisUtterance* currentSpeechUtterance();
    void startSpeakingImmediately();
    void startSpeakingImmediately(SpeechSynthesisUtterance*);
    void fireEvent(EventTypeNames, SpeechSynthesisUtterance*, int, String);
    void handleSpeakingCompleted(SpeechSynthesisUtterance*, bool);
};

#define ASSERT(expr) ((void)0)