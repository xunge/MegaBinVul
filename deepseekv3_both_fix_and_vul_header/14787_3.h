#include <stdint.h>
#include <string>
#include <iostream>

enum StartingPhase {
  SCRIPT_EVALUATED
};

enum ServiceWorkerStatusCode {
  SERVICE_WORKER_OK,
  SERVICE_WORKER_ERROR_SCRIPT_EVALUATE_FAILED
};

namespace base {
class TimeTicks {
 public:
  static TimeTicks Now();
  TimeTicks operator-(const TimeTicks& other) const;
  bool is_null() const { return false; }
};
}  // namespace base

class Histogram {
 public:
  static void AddTime(const std::string& name, const base::TimeTicks& time);
};

#define UMA_HISTOGRAM_TIMES(name, time) Histogram::AddTime(name, time)
#define DVLOG(level) std::cout

template <typename T>
class Callback {
 public:
  bool is_null() const { return false; }
  void Reset() {}
  void Run(T result) {}
};

typedef Callback<ServiceWorkerStatusCode> StatusCallback;

class EmbeddedWorkerInstance {
 public:
  void OnScriptEvaluated(bool success);
  StartingPhase starting_phase_;
  StatusCallback start_callback_;
  base::TimeTicks start_timing_;
};