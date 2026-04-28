#include <vector>
#include <map>
#include <string>

class GURL {
public:
    GURL(const std::string& url);
};

namespace BrowserThread {
    enum UI {};
}

#define DCHECK_CURRENTLY_ON(thread) 

class Referrer {
public:
    static Referrer SanitizeForRequest(const GURL& url, const Referrer& referrer);
};

namespace SaveFileCreateInfo {
    enum SaveFileSource {};
}

class SavePackage;

class SaveItem {
public:
    SaveItem(const GURL& url, const Referrer& referrer, SavePackage* package, 
             SaveFileCreateInfo::SaveFileSource source, int save_item_id, int container_id);
    SaveItem(const GURL& url, const Referrer& referrer, SavePackage* package,
             SaveFileCreateInfo::SaveFileSource source, int save_item_id);
};

class SavePackage {
public:
    SaveItem* CreatePendingSaveItem(
        int container_frame_tree_node_id,
        int save_item_frame_tree_node_id,
        const GURL& url,
        const Referrer& referrer,
        SaveFileCreateInfo::SaveFileSource save_source);
    
    std::vector<SaveItem*> waiting_item_queue_;
    std::map<int, std::vector<SaveItem*>> frame_tree_node_id_to_contained_save_items_;
};