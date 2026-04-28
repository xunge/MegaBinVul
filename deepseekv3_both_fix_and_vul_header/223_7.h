#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ERR_EXPLAIN(msg)
#define ERR_FAIL()
#define ERR_FAIL_COND(cond)
#define ERR_CONTINUE(cond)
#define OK 0
#define ABS(x) ((x) < 0 ? -(x) : (x))

class StringName;
class Variant;

class CharString {
public:
    const char* get_data() const;
};

class String {
public:
    String();
    String(const char* p_str);
    String(const StringName& p_name);
    String(const class NodePath& p_path);
    
    CharString utf8() const;
};

class Node {
public:
    class Path {
    public:
        Path rel_path_to(const Path& p_path) const;
        bool is_empty() const;
    };
    Path get_path() const;
};

class NodePath {
public:
    NodePath();
    NodePath(const String& p_path);
    NodePath(const Node::Path& p_path);
    bool is_empty() const;
};

class Error {
public:
    operator bool() const { return false; }
};

template<class T>
class Ref {
public:
    bool is_null() const { return false; }
    T* operator->() { return nullptr; }
};

class NetworkedMultiplayerPeer {
public:
    enum ConnectionStatus {
        CONNECTION_DISCONNECTED,
        CONNECTION_CONNECTING,
        CONNECTION_CONNECTED
    };
    
    enum TransferMode {
        TRANSFER_MODE_UNRELIABLE,
        TRANSFER_MODE_RELIABLE
    };

    virtual ConnectionStatus get_connection_status() const = 0;
    virtual int get_unique_id() const = 0;
    virtual void set_target_peer(int p_peer) = 0;
    virtual void set_transfer_mode(TransferMode p_mode) = 0;
    virtual void put_packet(const uint8_t *p_buffer, int p_buffer_size) = 0;
    virtual bool is_object_decoding_allowed() const = 0;
};

template<class K, class V>
class Map {
public:
    V& operator[](const K& p_key);
    V* getptr(const K& p_key);
    struct Element {
        const K& key() const;
        V& get() const;
        Element* next();
    };
    Element* find(const K& p_key) const;
};

template<class T>
class Set {
public:
    bool has(const T& p_val) const;
    struct Element {
        const T& get() const;
        Element* next();
    };
    Element* front() const;
};

template<class T>
class Vector {
public:
    int size() const;
    void resize(int p_size);
    T* write;
    const T* ptr() const;
};

enum NetworkCommands {
    NETWORK_COMMAND_REMOTE_SET,
    NETWORK_COMMAND_REMOTE_CALL
};

struct PathSentCache {
    int id;
    Map<int, bool> confirmed_peers;
};

class MultiplayerAPI {
    Ref<NetworkedMultiplayerPeer> network_peer;
    Node* root_node;
    Map<NodePath, PathSentCache> path_send_cache;
    int last_send_cache_id;
    Set<int> connected_peers;
    Vector<uint8_t> packet_cache;

    bool _send_confirm_path(const NodePath& p_path, PathSentCache* psc, int p_to);
    static uint32_t encode_uint32(uint32_t p_val, uint8_t* p_buf);
    static int encode_cstring(const char* p_string, uint8_t* p_buf);
    static Error encode_variant(const Variant& p_variant, uint8_t* p_buf, int& r_len, bool p_allow_objects = true);
    void _send_rpc(Node *p_from, int p_to, bool p_unreliable, bool p_set, const StringName &p_name, const Variant **p_arg, int p_argcount);
};