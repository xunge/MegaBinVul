#include <stddef.h>

namespace blink {
class WebMediaStreamSource {};
}

class WebAudioCapturerSource {
public:
    WebAudioCapturerSource();
    WebAudioCapturerSource(const blink::WebMediaStreamSource& blink_source);
    
private:
    void* track_;
    bool audio_format_changed_;
    blink::WebMediaStreamSource blink_source_;
};