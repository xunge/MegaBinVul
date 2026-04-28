#include <string>

#define OS_ANDROID
#define TTS_EVENT_INTERRUPTED 0
const int kInvalidCharIndex = -1;

class TtsEngineDelegate {
public:
    void Stop(void* utterance);
};

class Utterance {
public:
    std::string extension_id() const;
    void OnTtsEvent(int event, int char_index, const std::string& error_message);
};

class PlatformImpl {
public:
    void clear_error();
    void StopSpeaking();
};

class TtsControllerImpl {
private:
    bool paused_;
    Utterance* current_utterance_;
    TtsEngineDelegate* tts_engine_delegate_;

    PlatformImpl* GetPlatformImpl();
    void FinishCurrentUtterance();
    void ClearUtteranceQueue(bool clear_all);
public:
    void Stop();
};