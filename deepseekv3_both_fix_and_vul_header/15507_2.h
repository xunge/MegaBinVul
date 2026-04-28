#include <string>

#define BUILDFLAG(flag) 0

class WebUI;
class Profile {
public:
    bool IsGuestSession() const;
};
class GURL {
public:
    bool SchemeIs(const std::string& scheme) const;
    std::string host_piece() const;
    bool is_valid() const;
    std::string path() const;
};

namespace content {
extern const char kBraveUIScheme[];
extern const char kChromeUIScheme[];
bool HasWebUIScheme(const GURL& url);
}  // namespace content

namespace base {
class FeatureList {
public:
    static bool IsEnabled(const std::string& feature);
};
}  // namespace base

namespace skus {
namespace features {
extern const char kSkusFeature[];
}  // namespace features
}  // namespace skus

namespace brave_news {
namespace features {
extern const char kBraveNewsFeedUpdate[];
}  // namespace features
}  // namespace brave_news

namespace brave_shields {
namespace features {
extern const char kBraveAdblockCookieListOptIn[];
}  // namespace features
}  // namespace brave_shields

namespace brave_wallet {
bool IsAllowedForContext(Profile* profile);
}  // namespace brave_wallet

namespace ipfs {
class IpfsServiceFactory {
public:
    static bool IsIpfsEnabled(Profile* profile);
};
}  // namespace ipfs

namespace chrome {
extern const char kChromeUINewTabHost[];
extern const char kChromeUISettingsHost[];
extern const char kChromeUIWelcomeURL[];
}  // namespace chrome

extern const char kAdblockHost[];
extern const char kAdblockInternalsHost[];
extern const char kWebcompatReporterHost[];
extern const char kSkusInternalsHost[];
extern const char kIPFSWebUIHost[];
extern const char kWalletPageHost[];
extern const char kWalletSwapPagePath[];
extern const char kWalletSendPagePath[];
extern const char kWalletBuyPagePath[];
extern const char kWalletDepositPagePath[];
extern const char kBraveNewsInternalsHost[];
extern const char kWalletPanelHost[];
extern const char kBraveRewardsPanelHost[];
extern const char kBraveTipPanelHost[];
extern const char kSpeedreaderPanelHost[];
extern const char kWelcomeHost[];
extern const char kShieldsPanelHost[];
extern const char kCookieListOptInHost[];
extern const char kTorInternalsHost[];
extern const char kRewardsPageHost[];
extern const char kRewardsInternalsHost[];

typedef void* (*WebUIFactoryFunction)(WebUI*, Profile*, const GURL&);
void* NewWebUI(WebUI* web_ui, Profile* profile, const GURL& url);