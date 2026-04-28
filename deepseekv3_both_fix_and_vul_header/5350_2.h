#include <vector>
#include <string>
#include <cassert>

#define DCHECK(condition) assert(condition)

class BrowserThread {
public:
    static bool CurrentlyOn(int thread_id);
    static const int IO;
};

class IndexedDBContext {
public:
    class TaskRunner {
    public:
        bool RunsTasksOnCurrentThread();
    };
    TaskRunner* TaskRunner();
};

class IndexedDBDispatcherHost {
public:
    void OnAckReceivedBlobs(const std::vector<std::string>& uuids);
private:
    IndexedDBContext* indexed_db_context_;
    void DropBlobData(const std::string& uuid);
    void DropBlobDataHandle(const std::string& uuid);
};