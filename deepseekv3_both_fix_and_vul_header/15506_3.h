#include <string>

#define BUILDFLAG(x) 0

class GURL {
public:
    class Replacements {
    public:
        void SetSchemeStr(const std::string&);
        void SetHostStr(const std::string&);
        void SetPathStr(const std::string&);
    };
    
    GURL(const std::string&);
    std::string host() const;
    bool SchemeIs(const std::string&) const;
    GURL ReplaceComponents(const Replacements&) const;
};

class PrefService;

namespace content {
class BrowserContext;
extern const char kBraveUIScheme[];
extern const char kChromeUIScheme[];
}  // namespace content

namespace chrome {
extern const char kChromeUISyncHost[];
extern const char kChromeUISettingsHost[];
extern const char kChromeUIWelcomeHost[];
extern const char kChromeUIWelcomeURL[];
}  // namespace chrome

extern const char kBraveSyncPath[];
extern const char kAdblockHost[];
extern const char kContentFiltersPath[];

namespace brave_wallet {
namespace mojom {
enum class DefaultWallet { CryptoWallets };
}  // namespace mojom

mojom::DefaultWallet GetDefaultEthereumWallet(PrefService*);
bool IsNativeWalletEnabled();
}  // namespace brave_wallet

class EthereumRemoteClientServiceFactory;
class ExtensionRegistry;

extern const char ethereum_remote_client_host[];
extern const char ethereum_remote_client_extension_id[];
extern const char ethereum_remote_client_base_url[];

class BraveContentBrowserClient {
public:
    bool HandleURLOverrideRewrite(GURL*, content::BrowserContext*);
};