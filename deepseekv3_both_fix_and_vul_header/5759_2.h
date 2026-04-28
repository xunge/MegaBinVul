#include <string>
#include <vector>
#include <iostream>

class TransportSecurityState {
public:
    struct HashValue {};
    using HashValueVector = std::vector<HashValue>;

    bool CheckPublicKeyPins(const std::string& host,
                          bool is_issued_by_known_root,
                          const HashValueVector& public_key_hashes,
                          std::string* pinning_failure_log);
    bool HasPublicKeyPins(const std::string& host);
    bool CheckPublicKeyPinsImpl(const std::string& host,
                              const HashValueVector& public_key_hashes,
                              std::string* pinning_failure_log);
    void ReportUMAOnPinFailure(const std::string& host);
};

#define LOG(severity) std::cerr
#define ERROR 
#define UMA_HISTOGRAM_BOOLEAN(name, value)