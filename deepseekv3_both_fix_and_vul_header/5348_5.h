#include <stdbool.h>
#include <assert.h>

#define DCHECK assert

namespace IPC {
    class Message {
    public:
        int type() const;
    };
}

struct IndexedDBHostMsg_DatabasePut {
    static const int ID;
};
struct IndexedDBHostMsg_AckReceivedBlobs {
    static const int ID;
};
struct IndexedDBHostMsg_FactoryGetDatabaseNames {
    static const int ID;
};
struct IndexedDBHostMsg_FactoryOpen {
    static const int ID;
};
struct IndexedDBHostMsg_FactoryDeleteDatabase {
    static const int ID;
};

const int IndexedDBHostMsg_DatabasePut::ID = 1;
const int IndexedDBHostMsg_AckReceivedBlobs::ID = 2;
const int IndexedDBHostMsg_FactoryGetDatabaseNames::ID = 3;
const int IndexedDBHostMsg_FactoryOpen::ID = 4;
const int IndexedDBHostMsg_FactoryDeleteDatabase::ID = 5;

#define IPC_MESSAGE_CLASS(message) (0)
#define IPC_MESSAGE_HANDLER(msg, func)
#define IPC_BEGIN_MESSAGE_MAP(class, msg)
#define IPC_END_MESSAGE_MAP()
#define IPC_MESSAGE_UNHANDLED(code)

struct IndexedDBContext {
    struct TaskRunner* TaskRunner();
};

struct TaskRunner {
    bool RunsTasksOnCurrentThread();
};

struct DatabaseDispatcherHost {
    bool OnMessageReceived(const IPC::Message&);
};

struct CursorDispatcherHost {
    bool OnMessageReceived(const IPC::Message&);
};

enum {
    IndexedDBMsgStart
};

class IndexedDBDispatcherHost {
public:
    bool OnMessageReceived(const IPC::Message& message);
    void OnIDBFactoryGetDatabaseNames();
    void OnIDBFactoryOpen();
    void OnIDBFactoryDeleteDatabase();
    void OnAckReceivedBlobs();

    IndexedDBContext* indexed_db_context_;
    DatabaseDispatcherHost* database_dispatcher_host_;
    CursorDispatcherHost* cursor_dispatcher_host_;
};