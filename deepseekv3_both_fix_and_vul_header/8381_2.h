#include <string>
#include <cassert>

struct GURL {
    // Minimal definition
};

struct Referrer {
    // Minimal definition  
};

class SavePackage {
    // Minimal definition
};

namespace SaveFileCreateInfo {
    enum SaveFileSource {
        // Minimal enum definition
    };
}

class SaveItem {
public:
    enum SaveState {
        WAIT_START,
    };

    SaveItem(const GURL& url,
            const Referrer& referrer,
            SavePackage* package,
            SaveFileCreateInfo::SaveFileSource save_source,
            int frame_tree_node_id,
            int container_frame_tree_node_id);
            
    SaveItem(const GURL& url,
            const Referrer& referrer,
            SavePackage* package,
            SaveFileCreateInfo::SaveFileSource save_source,
            int frame_tree_node_id);

private:
    static int GetNextSaveItemId();
    
    int save_item_id_;
    GURL url_;
    Referrer referrer_;
    int frame_tree_node_id_;
    int container_frame_tree_node_id_;
    int total_bytes_;
    int received_bytes_;
    SaveState state_;
    bool is_success_;
    SaveFileCreateInfo::SaveFileSource save_source_;
    SavePackage* package_;
};

#define DCHECK(condition) assert(condition)