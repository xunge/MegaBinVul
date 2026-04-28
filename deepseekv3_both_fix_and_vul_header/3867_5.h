#include <map>
#include <thread>

class SQLDispatcher {
public:
    void join();
    void OnNotify();
};

typedef std::map<int, void*> ConnMap;

class ModuleSQL {
public:
    ~ModuleSQL();
private:
    SQLDispatcher* Dispatcher;
    ConnMap connections;
};

void mysql_library_end();