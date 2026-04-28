#include <atomic>
#include <memory>

class BrowserThread {
public:
  static bool CurrentlyOn(int thread_id);
  static const int UI;
};

class TtsController {
public:
  static TtsController* GetInstance();
  void RemoveVoicesChangedDelegate(class TtsMessageFilter* delegate);
};

template <typename T>
class WeakPtrFactory {
public:
  bool HasWeakPtrs() const;
};

class TtsMessageFilter {
public:
  ~TtsMessageFilter();
private:
  WeakPtrFactory<TtsMessageFilter> weak_ptr_factory_;
  void Cleanup();
};

#define CHECK(condition) (void)(condition)
#define DCHECK(condition) (void)(condition)