#include <string>
#include <stdint.h>
#include <memory>

class GURL;

namespace webkit {
namespace ppapi {

class PluginDelegate {
 public:
  class PlatformAudioInput;
  class PlatformAudioInputClient;
};

}  // namespace ppapi
}  // namespace webkit

class PepperPluginDelegateImpl {
 public:
  std::weak_ptr<PepperPluginDelegateImpl> AsWeakPtr();
  
  webkit::ppapi::PluginDelegate::PlatformAudioInput* CreateAudioInput(
      const std::string& device_id,
      const GURL& document_url,
      uint32_t sample_rate,
      uint32_t sample_count,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);
  
  webkit::ppapi::PluginDelegate::PlatformAudioInput* CreateAudioInput(
      const std::string& device_id,
      uint32_t sample_rate,
      uint32_t sample_count,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);
};

class PepperPlatformAudioInputImpl {
 public:
  static webkit::ppapi::PluginDelegate::PlatformAudioInput* Create(
      std::weak_ptr<PepperPluginDelegateImpl> delegate,
      const std::string& device_id,
      const GURL& document_url,
      int sample_rate,
      int sample_count,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);
  
  static webkit::ppapi::PluginDelegate::PlatformAudioInput* Create(
      std::weak_ptr<PepperPluginDelegateImpl> delegate,
      const std::string& device_id,
      int sample_rate,
      int sample_count,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);
};