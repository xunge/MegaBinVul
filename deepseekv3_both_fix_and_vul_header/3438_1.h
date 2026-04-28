class ExecutionContext;
class PlatformSpeechSynthesizer;
class ScriptWrappable;

class ContextLifecycleObserver {
public:
    ContextLifecycleObserver(ExecutionContext*);
};

class SpeechSynthesis : public ContextLifecycleObserver {
public:
    explicit SpeechSynthesis(ExecutionContext*);
private:
    PlatformSpeechSynthesizer* m_platformSpeechSynthesizer;
    void* m_currentSpeechUtterance;
    bool m_isPaused;
};

class PlatformSpeechSynthesizer {
public:
    static PlatformSpeechSynthesizer* create(SpeechSynthesis*);
};

class ScriptWrappable {
public:
    static void init(SpeechSynthesis*);
};