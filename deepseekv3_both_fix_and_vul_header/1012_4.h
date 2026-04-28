#include <string>
#include <sstream>
#include <iostream>
#include <memory>

typedef unsigned short session_t;
typedef float f32;

struct v3f {
    float x, y, z;
    float getDistanceFrom(const v3f &other) const { return 0.0f; }
};

class InventoryLocation {
public:
    enum Type {
        PLAYER,
        NODEMETA
    };
    Type type;
    std::string name;
    v3f p;
    std::string dump() const { return ""; }
    void applyCurrentPlayer(const std::string &name) {}
    bool operator!=(const InventoryLocation& other) const { return false; }
};

class PlayerSAO {
public:
    v3f getEyePosition() const { return v3f(); }
    bool isDead() const { return false; }
};

class RemotePlayer {
public:
    std::string getName() const { return ""; }
    PlayerSAO* getPlayerSAO() const { return nullptr; }
};

class NetworkPacket {
public:
    session_t getPeerId() const { return 0; }
    const char* getString(size_t index) const { return ""; }
    size_t getSize() const { return 0; }
};

class IAction {
public:
    enum Type {
        Move,
        Drop,
        Craft
    };
    virtual Type getType() const = 0;
    virtual ~IAction() {}
};

class InventoryAction : public IAction {
public:
    virtual ~InventoryAction() {}
    virtual void apply(class InventoryManager*, PlayerSAO*, class Server*) = 0;
    static InventoryAction* deSerialize(std::istream& is) { return nullptr; }
};

class RollbackScopeActor {
public:
    RollbackScopeActor(void* rollback, const std::string& name) {}
};

class InventoryManager {
public:
    void setInventoryModified(const InventoryLocation& loc) {}
};

class ServerEnvironment {
public:
    RemotePlayer* getPlayer(session_t peer_id) { return nullptr; }
};

class IMoveAction : public InventoryAction {
public:
    InventoryLocation from_inv;
    InventoryLocation to_inv;
    std::string from_list;
    std::string to_list;
    IAction::Type getType() const override { return IAction::Move; }
    void apply(InventoryManager*, PlayerSAO*, class Server*) override {}
};

class IDropAction : public InventoryAction {
public:
    InventoryLocation from_inv;
    std::string from_list;
    IAction::Type getType() const override { return IAction::Drop; }
    void apply(InventoryManager*, PlayerSAO*, class Server*) override {}
};

class ICraftAction : public InventoryAction {
public:
    InventoryLocation craft_inv;
    IAction::Type getType() const override { return IAction::Craft; }
    void apply(InventoryManager*, PlayerSAO*, class Server*) override {}
};

class Server {
protected:
    ServerEnvironment* m_env;
    std::unique_ptr<InventoryManager> m_inventory_mgr;
    void* m_rollback;
    
    void DisconnectPeer(session_t peer_id) {}
    bool checkInteractDistance(RemotePlayer* player, float distance, const std::string& what) { return true; }
    bool checkPriv(const std::string& name, const std::string& priv) { return true; }
public:
    void handleCommand_InventoryAction(NetworkPacket* pkt);
};

extern std::ostream errorstream;
extern std::ostream infostream;
extern std::ostream verbosestream;

const float BS = 1.0f;
v3f intToFloat(const v3f &p, float factor) { return p; }