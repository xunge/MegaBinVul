#include <cstdbool>

namespace IPC {
struct Message {
  int type() const;
};
}

class IndexedDBContext;

class TaskRunner {
public:
    bool RunsTasksOnCurrentThread();
};

class IndexedDBDispatcherHost {
public:
    class DatabaseDispatcherHost {
    public:
        bool OnMessageReceived(const IPC::Message& message);
        IndexedDBDispatcherHost* parent_;
        IndexedDBContext* indexed_db_context_;
    };
    IndexedDBContext* indexed_db_context_;
};

struct IndexedDBHostMsg_DatabasePut {
    static const int ID;
};
struct IndexedDBHostMsg_AckReceivedBlobs {
    static const int ID;
};
struct IndexedDBHostMsg_DatabaseCreateObjectStore {};
struct IndexedDBHostMsg_DatabaseDeleteObjectStore {};
struct IndexedDBHostMsg_DatabaseCreateTransaction {};
struct IndexedDBHostMsg_DatabaseClose {};
struct IndexedDBHostMsg_DatabaseVersionChangeIgnored {};
struct IndexedDBHostMsg_DatabaseDestroyed {};
struct IndexedDBHostMsg_DatabaseGet {};
struct IndexedDBHostMsg_DatabaseSetIndexKeys {};
struct IndexedDBHostMsg_DatabaseSetIndexesReady {};
struct IndexedDBHostMsg_DatabaseOpenCursor {};
struct IndexedDBHostMsg_DatabaseCount {};
struct IndexedDBHostMsg_DatabaseDeleteRange {};
struct IndexedDBHostMsg_DatabaseClear {};
struct IndexedDBHostMsg_DatabaseCreateIndex {};
struct IndexedDBHostMsg_DatabaseDeleteIndex {};
struct IndexedDBHostMsg_DatabaseAbort {};
struct IndexedDBHostMsg_DatabaseCommit {};

class DCHECK {
public:
    DCHECK(bool condition);
};

#define IPC_BEGIN_MESSAGE_MAP(class_name, message)
#define IPC_MESSAGE_HANDLER(message, function)
#define IPC_MESSAGE_UNHANDLED(expression)
#define IPC_END_MESSAGE_MAP()

class IndexedDBContext {
public:
    ::TaskRunner* TaskRunner();
};