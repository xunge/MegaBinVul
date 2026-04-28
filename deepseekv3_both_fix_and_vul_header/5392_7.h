#include <vector>
#include <map>
#include <memory>

typedef unsigned long XID;
typedef unsigned long XAtom;

struct AtomCache {
  XAtom GetAtom(const char* name);
};

struct SelectionFormatMap {
  struct Data {
    unsigned char* front();
    size_t size();
  };
  std::map<XAtom, std::shared_ptr<Data>> format_map_;
  typedef std::map<XAtom, std::shared_ptr<Data>>::const_iterator const_iterator;
  
  const_iterator find(XAtom target) const { return format_map_.find(target); }
  const_iterator end() const { return format_map_.end(); }
};

struct TimeDelta {
  static TimeDelta FromMilliseconds(int ms);
};

struct TimeTicks {
  static TimeTicks Now();
  TimeTicks operator+(const TimeDelta& delta) const;
};

struct Timer {
  template<typename T>
  void Start(int from_here, TimeDelta delay, T* owner, void (T::*method)()) {
    // Implementation would store these and call (owner->*method)() when timer fires
  }
  bool IsRunning() const;
};

struct XForeignWindowManager {
  static XForeignWindowManager* GetInstance();
  int RequestEvents(XID window, long event_mask);
};

struct IncrementalTransfer {
  XID requestor;
  XAtom target;
  XAtom property;
  std::shared_ptr<SelectionFormatMap::Data> data;
  size_t offset;
  TimeTicks timeout;
  int foreign_window_manager_id;
  
  IncrementalTransfer(XID r, XAtom t, XAtom p, std::shared_ptr<SelectionFormatMap::Data> d,
                     size_t o, TimeTicks tm, int f)
      : requestor(r), target(t), property(p), data(d), offset(o), timeout(tm),
        foreign_window_manager_id(f) {}
};

struct SelectionOwner {
  AtomCache atom_cache_;
  void* x_display_;
  SelectionFormatMap format_map_;
  size_t max_request_size_;
  std::vector<IncrementalTransfer> incremental_transfers_;
  Timer incremental_transfer_abort_timer_;
  
  bool ProcessTarget(XAtom target, XID requestor, XAtom property);
  void RetrieveTargets(std::vector<XAtom>* targets);
  void AbortStaleIncrementalTransfers();
};

void XChangeProperty(void* display, XID window, XAtom property, XAtom type,
                    int format, int mode, const unsigned char* data, int nelements);

const char* kMultiple = "MULTIPLE";
const char* kSaveTargets = "SAVE_TARGETS";
const char* kTargets = "TARGETS";
const char* kIncr = "INCR";
const int kIncrementalTransferTimeoutMs = 1000;
const int kTimerPeriodMs = 1000;
const long PropertyChangeMask = 0x04000000L;
const int XA_ATOM = 4;
const int PropModeReplace = 0;
const int FROM_HERE = 0;

namespace base {
using ::TimeDelta;
using ::TimeTicks;
}

namespace ui {
using ::XForeignWindowManager;
}