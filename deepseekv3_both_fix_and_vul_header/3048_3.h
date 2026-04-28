#include <string>
#include <memory>

class GURL;

namespace base {
template <typename T>
class WeakPtr {
 public:
  WeakPtr() : ptr_(nullptr) {}
  WeakPtr(T* ptr) : ptr_(ptr) {}
  T* get() { return ptr_; }
 private:
  T* ptr_;
};
}  // namespace base

namespace webkit {
namespace ppapi {
class PluginDelegate {
 public:
  class PlatformAudioInputClient;
};
}  // namespace ppapi
}  // namespace webkit

class PepperPluginDelegateImpl;

template <typename T>
class scoped_refptr {
 public:
  scoped_refptr(T* ptr) : ptr_(ptr) {}
  T* get() { return ptr_; }
  T* operator->() { return ptr_; }
 private:
  T* ptr_;
};

class PepperPlatformAudioInputImpl {
 public:
  static PepperPlatformAudioInputImpl* Create(
      const base::WeakPtr<PepperPluginDelegateImpl>& plugin_delegate,
      const std::string& device_id,
      const GURL& document_url,
      int sample_rate,
      int frames_per_buffer,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);
  
  static PepperPlatformAudioInputImpl* Create(
      const base::WeakPtr<PepperPluginDelegateImpl>& plugin_delegate,
      const std::string& device_id,
      int sample_rate,
      int frames_per_buffer,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);

  bool Initialize(
      const base::WeakPtr<PepperPluginDelegateImpl>& plugin_delegate,
      const std::string& device_id,
      const GURL& document_url,
      int sample_rate,
      int frames_per_buffer,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);

  bool Initialize(
      const base::WeakPtr<PepperPluginDelegateImpl>& plugin_delegate,
      const std::string& device_id,
      int sample_rate,
      int frames_per_buffer,
      webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);

  void AddRef();
  void ShutDownOnIOThread();
};