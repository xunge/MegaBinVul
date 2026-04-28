#include <memory>
#include <functional>

namespace base {
class TimeDelta {
 public:
  static TimeDelta FromMilliseconds(long long ms);
};

template <typename T>
class Passed {
 public:
  explicit Passed(T* ptr);
};

template <typename T, typename... Args>
std::function<void()> Bind(T&& f, Args&&... args);

class Location {
 public:
  Location(const char* function_name, const char* file_name, int line_number, const void* program_counter);
};

class TaskRunner {
 public:
  void PostDelayedTask(const Location& location, std::function<void()> task, TimeDelta delay);
  void PostNonNestableDelayedTask(const Location& location, std::function<void()> task, TimeDelta delay);
};

template <typename T>
class scoped_refptr {
 public:
  T* operator->();
};
}  // namespace base

namespace tracked_objects {
using Location = base::Location;
}  // namespace tracked_objects

namespace blink {
class WebThread {
 public:
  class Task {
   public:
    virtual ~Task() {}
    virtual void run() = 0;
  };
};

class WebTraceLocation {
 public:
  const char* functionName() const;
  const char* fileName() const;
};
}  // namespace blink

template <typename T>
class scoped_ptr {
 public:
  explicit scoped_ptr(T* ptr);
  T* operator->();
};

class WebSchedulerImpl {
 public:
  void postTimerTask(const blink::WebTraceLocation& web_location,
                    blink::WebThread::Task* task,
                    long long delayMs);
  void runTask(scoped_ptr<blink::WebThread::Task> task);
  base::scoped_refptr<base::TaskRunner> timer_task_runner_;
};

#define DCHECK(condition)