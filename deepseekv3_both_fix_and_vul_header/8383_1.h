#include <string>

class GURL {
public:
    bool is_valid() const;
    bool SchemeIsFile() const;
};

class Referrer {
};

class BrowserThread {
public:
    static void UI();
};

class FrameTreeNode {
public:
    static const int kFrameTreeNodeInvalidId;
};

class SaveFileCreateInfo {
public:
    enum SaveFileSource {
        SAVE_FILE_FROM_FILE,
        SAVE_FILE_FROM_NET
    };
};

class SavePackage {
public:
    void EnqueueSavableResource(int container_frame_tree_node_id,
                               const GURL& url,
                               const Referrer& referrer);
    void CreatePendingSaveItemDeduplicatingByUrl(
        int container_frame_tree_node_id,
        int frame_tree_node_id,
        const GURL& url,
        const Referrer& referrer,
        SaveFileCreateInfo::SaveFileSource save_source);
};

#define DCHECK_CURRENTLY_ON(thread)