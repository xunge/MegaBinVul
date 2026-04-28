#include <string>

class TtsControllerImpl {
public:
    void Pause();
    
private:
    bool paused_;
    class Utterance* current_utterance_;
    class TtsEngineDelegate* tts_engine_delegate_;
    
    class PlatformImpl* GetPlatformImpl();
};

class Utterance {
public:
    const std::string& extension_id() const;
};

class TtsEngineDelegate {
public:
    void Pause(Utterance* utterance);
};

class PlatformImpl {
public:
    void clear_error();
    void Pause();
};