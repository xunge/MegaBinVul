#include <string>

typedef int SaveItemId;
typedef int SavePackageId;

class net {
public:
    class URLRequest {};
};

class GURL {
public:
    GURL(const std::string& url) {}
};

class SaveFileManager {};

class ResourceHandler {
public:
    ResourceHandler(net::URLRequest* request) {}
};

enum AuthorizationState {
    NONE
};

class SaveFileResourceHandler : public ResourceHandler {
public:
    SaveFileResourceHandler(
        net::URLRequest* request,
        SaveItemId save_item_id,
        SavePackageId save_package_id,
        int render_process_host_id,
        int render_frame_routing_id,
        const GURL& url,
        SaveFileManager* manager,
        AuthorizationState authorization_state);
        
    SaveFileResourceHandler(
        net::URLRequest* request,
        SaveItemId save_item_id,
        SavePackageId save_package_id,
        int render_process_host_id,
        int render_frame_routing_id,
        const GURL& url,
        SaveFileManager* manager);
        
private:
    SaveItemId save_item_id_;
    SavePackageId save_package_id_;
    int render_process_id_;
    int render_frame_routing_id_;
    GURL url_;
    int content_length_;
    SaveFileManager* save_manager_;
    AuthorizationState authorization_state_;
};