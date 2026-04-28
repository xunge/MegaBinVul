#include <memory>
#include <string>
#include <cassert>

#define CHECK(expr) assert(expr)

struct BrowserThread {
  static bool CurrentlyOn(int thread_id);
  static const int UI;
};

struct TtsUtteranceRequest {
  int id;
  std::string text;
  std::string lang;
  std::string voice;
  double rate;
  double pitch;
  double volume;
};

struct UtteranceContinuousParameters {
  double rate;
  double pitch;
  double volume;
};

template <typename T>
class WeakPtr {
 public:
  T* get() const { return nullptr; }
  operator T*() const { return get(); }
};

template <typename T>
class WeakPtrFactory {
 public:
  WeakPtr<T> GetWeakPtr() { return WeakPtr<T>(); }
};

class Utterance {
 public:
  explicit Utterance(void* browser_context);
  void set_src_id(int id);
  void set_text(const std::string& text);
  void set_lang(const std::string& lang);
  void set_voice_name(const std::string& voice);
  void set_can_enqueue(bool can_enqueue);
  void set_continuous_parameters(const UtteranceContinuousParameters& params);
  void set_event_delegate(void* delegate);
};

class TtsController {
 public:
  static TtsController* GetInstance();
  void SpeakOrEnqueue(Utterance* utterance);
};

template <typename T>
class scoped_ptr {
 public:
  explicit scoped_ptr(T* ptr);
  ~scoped_ptr();
  T* operator->();
  T* release();
};

class TtsMessageFilter {
 public:
  void OnSpeak(const TtsUtteranceRequest& request);
 private:
  void* browser_context_;
  WeakPtrFactory<TtsMessageFilter> weak_ptr_factory_;
};

const int BrowserThread::UI = 0;