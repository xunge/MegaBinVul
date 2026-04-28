#include <string>

namespace url {
class GURL {
public:
  std::string GetOrigin() const;
};
bool IsSameOriginWith(const GURL&, const GURL&);
}  // namespace url

namespace content {
class LoadCommittedDetails;
class FrameNavigateParams {
public:
  url::GURL url;
  std::string GetOrigin() const;
};
class RenderProcessHost;
class WebContents {
public:
  content::RenderProcessHost* GetRenderProcessHost() const;
};
}  // namespace content

namespace bad_message {
enum BadMessageReason {
  EVG_BAD_ORIGIN
};
void ReceivedBadMessage(content::RenderProcessHost*, BadMessageReason);
}  // namespace bad_message

class ExtensionViewGuest {
public:
  bool attached() const;
  url::GURL url_;
  content::WebContents* web_contents() const;
  void DidNavigateMainFrame(const content::LoadCommittedDetails&,
                          const content::FrameNavigateParams&);
};