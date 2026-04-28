#include <memory>
#include <chrono>

class ProxyConfigService {
public:
    virtual ~ProxyConfigService() = default;
};

class ProxyResolverFactory {
public:
    virtual ~ProxyResolverFactory() = default;
};

class NetLog {
public:
    virtual ~NetLog() = default;
};

class NetworkChangeNotifier {
public:
    static void AddIPAddressObserver(void* observer);
    static void AddDNSObserver(void* observer);
};

class TimeDelta {
public:
    static TimeDelta FromMilliseconds(int ms);
};

enum class SanitizeUrlPolicy {
    SAFE
};

class ProxyService {
public:
    enum State {
        STATE_NONE
    };

    ProxyService(std::unique_ptr<ProxyConfigService> config_service,
                std::unique_ptr<ProxyResolverFactory> resolver_factory,
                NetLog* net_log);

    void ResetConfigService(std::unique_ptr<ProxyConfigService> config_service);

private:
    std::unique_ptr<ProxyResolverFactory> resolver_factory_;
    int next_config_id_;
    State current_state_;
    NetLog* net_log_;
    TimeDelta stall_proxy_auto_config_delay_;
    bool quick_check_enabled_;
    SanitizeUrlPolicy sanitize_url_policy_;
};

constexpr int kDelayAfterNetworkChangesMs = 100;