#include <memory>
#include <cassert>

#define CHECK assert

class BrowserThread {
public:
  static bool CurrentlyOn(int thread_id);
  static const int UI = 0;
};

class TtsMessageFilter;

class TtsController {
public:
  static TtsController* GetInstance();
  void RemoveVoicesChangedDelegate(TtsMessageFilter* delegate);
};

class TtsMessageFilter {
public:
  void OnChannelClosingInUIThread();
  void Cleanup();
  void Release();
  
  struct WeakPtrFactory {
    void InvalidateWeakPtrs();
  };
  WeakPtrFactory weak_ptr_factory_;
};