#include <vector>

namespace content {
class BrowserContext;
}

struct VoiceData;

class TtsEngineDelegate {
public:
    void GetVoices(content::BrowserContext* browser_context, std::vector<VoiceData>* out_voices);
};

class TtsPlatformImpl {
public:
    void LoadBuiltInTtsExtension(content::BrowserContext* browser_context);
    bool PlatformImplAvailable();
    void GetVoices(std::vector<VoiceData>* out_voices);
};

class TtsControllerImpl {
public:
    void GetVoices(content::BrowserContext* browser_context, std::vector<VoiceData>* out_voices);
private:
    TtsEngineDelegate* tts_engine_delegate_;
    TtsPlatformImpl* GetPlatformImpl();
};