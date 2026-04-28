#include <stdbool.h>
#include <vector>

namespace base {
void KillProcess(int handle, int result_code, bool wait);
}

namespace IPC {
class Message {
public:
  int type() const;
  int routing_id() const;
};
}

#define IPC_BEGIN_MESSAGE_MAP_EX(class_name, message, msg_is_ok)
#define IPC_MESSAGE_HANDLER(message_class, member_function)
#define IPC_MESSAGE_UNHANDLED(code)
#define IPC_END_MESSAGE_MAP_EX()

#define NOTREACHED()
#define UserMetricsAction(action) action
#define RESULT_CODE_KILLED_BAD_MESSAGE 0

struct WorkerHostMsg_WorkerContextClosed {};
struct WorkerProcessHostMsg_AllowDatabase {};
struct WorkerProcessHostMsg_AllowFileSystem {};
struct WorkerProcessHostMsg_AllowIndexedDB {};
struct WorkerHostMsg_WorkerContextDestroyed {
  static int ID;
};

class WorkerServiceImpl {
public:
  static WorkerServiceImpl* GetInstance();
  void NotifyWorkerDestroyed(void* host, int routing_id);
};

class WorkerProcessHost {
public:
  struct ProcessData {
    int handle;
    const ProcessData& GetData() const { return *this; }
  };
  
  struct Instance {
    int worker_route_id() const;
  };
  
  typedef std::vector<Instance> Instances;
  Instances instances_;
  
  ProcessData* process_;
  
  Instances::iterator begin() { return instances_.begin(); }
  Instances::iterator end() { return instances_.end(); }
  void erase(Instances::iterator it) { instances_.erase(it); }
  
  void UpdateTitle();
  void OnWorkerContextClosed();
  void OnAllowDatabase();
  void OnAllowFileSystem();
  void OnAllowIndexedDB();
  
  void RecordAction(const char* action);
  bool OnMessageReceived(const IPC::Message& message);
};