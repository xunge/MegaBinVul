#include <memory>

class WebFileSystemImpl {
public:
    static void DeleteThreadSpecificInstance();
};

struct FileSystemDispatcher {};
struct QuotaDispatcher {};

class ChildThread {
public:
    void Shutdown();
    std::unique_ptr<FileSystemDispatcher> file_system_dispatcher_;
    std::unique_ptr<QuotaDispatcher> quota_dispatcher_;
};