#include <vector>
#include <string>
#include <cstdint>

namespace gfx {
struct Point {
    int x;
    int y;
};
}

class base {
public:
    class FilePath {
    public:
        static FilePath FromUTF8Unsafe(const std::string& utf8);
        std::string AsUTF8Unsafe() const;
    };
    static std::string UTF16ToUTF8(const std::u16string& utf16);
    static std::u16string UTF8ToUTF16(const std::string& utf8);
};

namespace fileapi {
class IsolatedContext {
public:
    class FileInfoSet {
    public:
        void AddPath(const base::FilePath& path, std::string* name);
        void AddPathWithName(const base::FilePath& path, const std::string& name);
    };
    static IsolatedContext* GetInstance();
    std::string RegisterDraggedFileSystem(const FileInfoSet& files);
};
}

namespace net {
class FileURL {
public:
    static FileURL FromPath(const base::FilePath& path);
};
FileURL FilePathToFileURL(const base::FilePath& path);
}

class DropData {
public:
    struct FileInfo {
        std::u16string path;
        std::u16string display_name;
    };
    std::vector<FileInfo> filenames;
    std::u16string url;
    bool did_originate_from_renderer;
    std::u16string filesystem_id;
};

class ChildProcessSecurityPolicyImpl {
public:
    static ChildProcessSecurityPolicyImpl* GetInstance();
    bool CanReadFile(int renderer_id, const base::FilePath& path);
    void GrantReadFile(int renderer_id, const base::FilePath& path);
    void GrantRequestSpecificFileURL(int renderer_id, const net::FileURL& url);
    void GrantReadFileSystem(int renderer_id, const std::string& filesystem_id);
};

class WebDragOperationsMask {};

class RenderProcessHost {
public:
    int GetID();
    void FilterURL(bool empty_permitted, std::u16string* url);
};

class DragMsg_TargetDragEnter {
public:
    DragMsg_TargetDragEnter(int routing_id, const DropData& drop_data,
                           const gfx::Point& client_pt,
                           const gfx::Point& screen_pt,
                           WebDragOperationsMask operations_allowed,
                           int key_modifiers);
};

class RenderViewHostImpl {
public:
    int GetRoutingID();
    RenderProcessHost* GetProcess();
    void Send(DragMsg_TargetDragEnter* msg);
    void DragTargetDragEnter(
        const DropData& drop_data,
        const gfx::Point& client_pt,
        const gfx::Point& screen_pt,
        WebDragOperationsMask operations_allowed,
        int key_modifiers);
};

#define DCHECK(condition) ((void)0)