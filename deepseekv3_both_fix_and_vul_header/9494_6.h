#include <string>
#include <vector>
#include <memory>

class GURL {
public:
    static GURL EmptyGURL();
    bool operator!=(const GURL& other) const;
    bool operator!=(const std::string& other) const;
    std::string spec() const;
};

class FrameTree;

class FrameTreeNode {
public:
    FrameTree* frame_tree();
    bool IsMainFrame();
    int frame_tree_node_id();
    void set_current_url(const GURL& url);
    class RenderManager {
    public:
        void DidNavigateFrame(class RenderFrameHostImpl* host);
    };
    RenderManager* render_manager();
};

class RenderFrameHostImpl {
public:
    FrameTreeNode* frame_tree_node();
    void* GetSiteInstance();
};

class FrameTree {
public:
    class Node {
    public:
        class RenderManager {
        public:
            void DidNavigateFrame(RenderFrameHostImpl* host);
        };
        RenderManager* render_manager();
    };
    Node* root();
};

class NavigationEntryImpl {
public:
    static NavigationEntryImpl* FromNavigationEntry(void* entry);
    int frame_tree_node_id();
};

class NavigationEntry {
public:
    int GetPageID();
    GURL GetURL();
    int GetTransitionType();
};

class SiteInstanceImpl {
public:
    bool HasSite();
    void SetSite(const GURL& url);
};

class CommandLine {
public:
    static CommandLine* ForCurrentProcess();
    bool HasSwitch(const std::string& switch_string);
};

enum PageTransition {
    PAGE_TRANSITION_AUTO_SUBFRAME,
    PAGE_TRANSITION_FORWARD_BACK
};

enum NavigationType {
    NAVIGATION_TYPE_NAV_IGNORE
};

struct FrameHostMsg_DidCommitProvisionalLoad_Params {
    PageTransition transition;
    int page_id;
    GURL url;
    bool was_within_same_page;
    std::string contents_mime_type;
    std::string frame_unique_name;
    FrameHostMsg_DidCommitProvisionalLoad_Params(const FrameHostMsg_DidCommitProvisionalLoad_Params&);
};

struct LoadCommittedDetails {
    NavigationType type;
    bool is_main_frame;
};

namespace switches {
extern const char kSitePerProcess[];
}

class NavigationController;
class NavigatorDelegate;

class NavigatorImpl {
public:
    void DidNavigate(RenderFrameHostImpl* render_frame_host,
                    const FrameHostMsg_DidCommitProvisionalLoad_Params& input_params);
private:
    bool ShouldAssignSiteForURL(const GURL& url);
    bool PageTransitionIsMainFrame(PageTransition transition);
    bool IsURLInPageNavigation(const GURL& url, bool was_within_same_page, RenderFrameHostImpl* render_frame_host);
    NavigationController* controller_;
    NavigatorDelegate* delegate_;
};

class NavigationController {
public:
    void* GetPendingEntry();
    NavigationEntry* GetLastCommittedEntry();
    bool IsURLInPageNavigation(const GURL& url, bool was_within_same_page, RenderFrameHostImpl* render_frame_host);
    bool RendererDidNavigate(RenderFrameHostImpl* render_frame_host,
                           const FrameHostMsg_DidCommitProvisionalLoad_Params& params,
                           LoadCommittedDetails* details);
    void TakeScreenshot();
};

class NavigatorDelegate {
public:
    bool CanOverscrollContent();
    void DidNavigateMainFramePreCommit(bool is_navigation_within_page);
    void DidNavigateMainFramePreCommit(const FrameHostMsg_DidCommitProvisionalLoad_Params& params);
    void SetMainFrameMimeType(const std::string& mime_type);
    void DidCommitProvisionalLoad(RenderFrameHostImpl* render_frame_host,
                                const std::string& frame_unique_name,
                                bool is_main_frame,
                                const GURL& url,
                                PageTransition transition_type);
    void DidNavigateMainFramePostCommit(const LoadCommittedDetails& details,
                                      const FrameHostMsg_DidCommitProvisionalLoad_Params& params);
    void DidNavigateAnyFramePostCommit(RenderFrameHostImpl* render_frame_host,
                                     const LoadCommittedDetails& details,
                                     const FrameHostMsg_DidCommitProvisionalLoad_Params& params);
};

PageTransition PageTransitionFromInt(int transition);