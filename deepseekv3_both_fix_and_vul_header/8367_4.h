#include <string>
#include <iostream>

namespace net {
    struct URLRequest {
        struct URL {
            std::string path() const { return ""; }
            std::string spec() const { return ""; }
            std::string GetWithEmptyPath() const { return ""; }
        };
        URL url() const { return URL(); }
    };
}

struct Extension {
    bool is_hosted_app() const { return false; }
    int manifest_version() const { return 0; }
    std::string url() const { return ""; }
};

struct InfoMap {
    struct Extensions {
        const Extension* GetByID(const std::string&) const { return nullptr; }
    };
    struct ProcessMap {
        bool Contains(int) const { return false; }
    };
    
    Extensions extensions() const { return Extensions(); }
    ProcessMap process_map() const { return ProcessMap(); }
};

struct WebViewRendererState {
    static WebViewRendererState* GetInstance() { return nullptr; }
    void GetOwnerInfo(int, int*, std::string*) {}
    bool GetPartitionID(int, std::string*) { return false; }
};

struct WebviewInfo {
    static bool IsResourceWebviewAccessible(const Extension*, const std::string&, const std::string&) { return false; }
};

struct WebAccessibleResourcesInfo {
    static bool IsResourceWebAccessible(const Extension*, const std::string&) { return false; }
    static bool HasWebAccessibleResources(const Extension*) { return false; }
};

struct IconsInfo {
    struct Icons {
        bool ContainsPath(const std::string&) const { return false; }
    };
    static Icons GetIcons(const Extension*) { return Icons(); }
};

namespace content {
    struct ResourceRequestInfo {
        static const ResourceRequestInfo* ForRequest(net::URLRequest*) { return nullptr; }
        int GetChildID() const { return 0; }
        int GetPageTransition() const { return 0; }
        int GetResourceType() const { return 0; }
    };
    bool IsResourceTypeFrame(int) { return false; }
    const int RESOURCE_TYPE_MAIN_FRAME = 0;
    const int RESOURCE_TYPE_SUB_FRAME = 1;
}

namespace ui {
    bool PageTransitionIsWebTriggerable(int) { return false; }
}

#define DCHECK_EQ(a, b) 
#define LOG(ERROR) std::cerr