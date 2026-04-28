#include <map>
#include <string>
#include <vector>
#include <variant>
#include <set>
#include <functional>
#include <nlohmann/json.hpp>

struct OlmMessage {
    std::string sender;
    std::string sender_key;
    std::map<std::string, struct Ciphertext> ciphertext;
};

struct Ciphertext {
    int type;
    std::string body;
};

struct UserKeyCache {
    struct DeviceKey {
        std::map<std::string, std::string> keys;
    };
    std::map<std::string, DeviceKey> device_keys;
};

namespace crypto {
    enum class Trust { Verified };
}

namespace mtx {
namespace events {
namespace msg {
    enum class RequestAction { Cancellation };
    
    struct KeyVerificationAccept {};
    struct KeyVerificationRequest {};
    struct KeyVerificationCancel {};
    struct KeyVerificationKey {};
    struct KeyVerificationMac {};
    struct KeyVerificationStart {};
    struct KeyVerificationReady {};
    struct KeyVerificationDone {};
    struct RoomKey {};
    struct ForwardedRoomKey {
        std::vector<std::string> forwarding_curve25519_key_chain;
    };
    struct SecretSend {
        std::string request_id;
        std::string secret;
    };
    struct SecretRequest {
        RequestAction action;
        std::string requesting_device_id;
        std::string request_id;
    };
    struct Dummy {};
}

template<typename Content>
struct DeviceEvent {
    Content content;
    std::string sender;
};

namespace collections {
    using DeviceEvents = std::variant<
        DeviceEvent<msg::KeyVerificationAccept>,
        DeviceEvent<msg::KeyVerificationRequest>,
        DeviceEvent<msg::KeyVerificationCancel>,
        DeviceEvent<msg::KeyVerificationKey>,
        DeviceEvent<msg::KeyVerificationMac>,
        DeviceEvent<msg::KeyVerificationStart>,
        DeviceEvent<msg::KeyVerificationReady>,
        DeviceEvent<msg::KeyVerificationDone>,
        DeviceEvent<msg::RoomKey>,
        DeviceEvent<msg::ForwardedRoomKey>,
        DeviceEvent<msg::SecretSend>,
        DeviceEvent<msg::SecretRequest>,
        DeviceEvent<msg::Dummy>
    >;
}
}

namespace responses {
namespace utils {
    void parse_device_events(const nlohmann::json&, std::vector<mtx::events::collections::DeviceEvents>&);
}
}

namespace identifiers {
    class User {
    public:
        std::string to_string() const;
        bool operator<(const User&) const;
    };
}

namespace http {
    class RequestErr {
    public:
        operator bool() const;
    };
}
}

namespace nhlog {
    class crypto {
    public:
        void info(const std::string&, const std::string&);
        void info(const std::string&, const std::string&, const std::string&);
        void warn(const std::string&);
        void warn(const std::string&, const std::string&);
        void error(const std::string&);
        void error(const std::string&, const std::string&);
        void debug(const std::string&, const std::string&, const std::string&);
    };
    crypto* crypto();
    class net {
    public:
        void error(const std::string&, const std::string&);
        void critical(const std::string&, const std::string&);
    };
    net* net();
}

namespace olm {
    class client {
    public:
        struct IdentityKeys {
            std::string ed25519;
            std::string curve25519;
        };
        IdentityKeys identity_keys();
    };
    client* client();
}

namespace http {
    class client {
    public:
        mtx::identifiers::User user_id();
        std::string device_id();
        template<typename T>
        void send_to_device(const std::string&, const std::map<mtx::identifiers::User, std::map<std::string, T>>&, std::function<void(mtx::http::RequestErr)>);
        std::string generate_txn_id();
    };
    client* client();
}

namespace cache {
    struct VerificationStatus {
        std::set<std::string> verified_devices;
        std::map<std::string, crypto::Trust> verified_device_keys;
    };
    VerificationStatus* verificationStatus(const std::string&);
    struct UserKeys {
        std::map<std::string, UserKeyCache::DeviceKey> device_keys;
    };
    UserKeys* userKeys(const std::string&);
    class client {
    public:
        void storeSecret(const std::string&, const std::string&);
    };
    client* client();
}

class ChatPage {
public:
    static ChatPage* instance();
    void receivedDeviceVerificationAccept(const mtx::events::msg::KeyVerificationAccept&);
    void receivedDeviceVerificationRequest(const mtx::events::msg::KeyVerificationRequest&, const std::string&);
    void receivedDeviceVerificationCancel(const mtx::events::msg::KeyVerificationCancel&);
    void receivedDeviceVerificationKey(const mtx::events::msg::KeyVerificationKey&);
    void receivedDeviceVerificationMac(const mtx::events::msg::KeyVerificationMac&);
    void receivedDeviceVerificationStart(const mtx::events::msg::KeyVerificationStart&, const std::string&);
    void receivedDeviceVerificationReady(const mtx::events::msg::KeyVerificationReady&);
    void receivedDeviceVerificationDone(const mtx::events::msg::KeyVerificationDone&);
};

nlohmann::json try_olm_decryption(const std::string&, const Ciphertext&);
nlohmann::json handle_pre_key_olm_message(const std::string&, const std::string&, const Ciphertext&);
void create_inbound_megolm_session(const mtx::events::DeviceEvent<mtx::events::msg::RoomKey>&, const std::string&, const std::string&);
void import_inbound_megolm_session(const mtx::events::DeviceEvent<mtx::events::msg::ForwardedRoomKey>&);
void handle_secret_request(const mtx::events::DeviceEvent<mtx::events::msg::SecretRequest>*, const std::string&);
void send_encrypted_to_device_messages(const std::map<std::string, std::vector<std::string>>&, const mtx::events::DeviceEvent<mtx::events::msg::Dummy>&, bool);

std::map<std::string, std::string> request_id_to_secret_name;