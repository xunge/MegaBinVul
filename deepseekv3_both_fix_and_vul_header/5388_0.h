#include <string>
#include <memory>

class Utterance;
class TtsEventDelegate;

enum TtsEventType {
};

class Utterance {
public:
    void OnTtsEvent(TtsEventType event_type, int char_index, const std::string& error_message);
    bool IsFinalTtsEventType(TtsEventType event_type);
    int char_index_;
    bool finished_;
    std::shared_ptr<TtsEventDelegate> event_delegate_;
};

class TtsEventDelegate {
public:
    virtual void OnTtsEvent(Utterance* utterance, TtsEventType event_type, int char_index, const std::string& error_message) = 0;
};