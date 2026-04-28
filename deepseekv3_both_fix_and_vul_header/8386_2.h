#include <deque>
#include <unordered_map>
#include <string>
#include <cassert>

#define DCHECK(condition) assert(condition)
#define DCHECK_CURRENTLY_ON(thread) 
#define DCHECK_NE(a, b) assert((a) != (b))

class BrowserThread {
public:
    static constexpr const char* UI = "UI";
};

class SaveItem {
public:
    std::string id();
    std::string url();
    std::string referrer();
    int save_source();
    int container_frame_tree_node_id();
    int frame_tree_node_id();
    void Start();
    void Finish(int, bool);
    std::string full_path();
};

class RenderFrameHostImpl {
public:
    class Process {
    public:
        int GetID();
    };
    Process* GetProcess();
    class RenderViewHost {
    public:
        int GetRoutingID();
    };
    RenderViewHost* render_view_host();
    int routing_id();
};

class FrameTreeNode {
public:
    static const int kFrameTreeNodeInvalidId = -1;
    static FrameTreeNode* GloballyFindByID(int);
    RenderFrameHostImpl* current_frame_host();
};

class SaveFileCreateInfo {
public:
    static const int SAVE_FILE_FROM_NET = 0;
};

class WebContents {
public:
    class RenderProcessHost {
    public:
        int GetID();
    };
    RenderProcessHost* GetRenderProcessHost();
    class RenderFrameHost {
    public:
        int GetRoutingID();
    };
    RenderFrameHost* GetMainFrame();
    class BrowserContext {
    public:
        void* GetResourceContext();
    };
    BrowserContext* GetBrowserContext();
};

class FileManager {
public:
    void SaveURL(const std::string& id, const std::string& url, const std::string& referrer,
                int process_id, int render_view_routing_id, int render_frame_routing_id,
                int save_source, const std::string& full_path, void* resource_context,
                void* callback);
};

class SavePackage {
public:
    void SaveNextFile(bool process_all_remaining_items);
    WebContents* web_contents();
    FileManager* file_manager_;
    int routing_id();
    std::deque<SaveItem*> waiting_item_queue_;
    std::unordered_map<std::string, SaveItem*> in_progress_items_;
};

template<typename T, typename U>
bool ContainsKey(const T& container, const U& key) {
    return container.find(key) != container.end();
}