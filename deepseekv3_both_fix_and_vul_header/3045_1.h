#include <string>
#include <stdint.h>

class GURL;

class MockPluginDelegate {
public:
    class PlatformAudioInput;
    class PlatformAudioInputClient;
    
    PlatformAudioInput* CreateAudioInput(
        const std::string& device_id,
        const GURL& document_url,
        uint32_t sample_rate,
        uint32_t sample_count,
        PlatformAudioInputClient* client);
        
    PlatformAudioInput* CreateAudioInput(
        const std::string& device_id,
        uint32_t sample_rate,
        uint32_t sample_count,
        PlatformAudioInputClient* client);
};