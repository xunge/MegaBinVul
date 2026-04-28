#include <stdint.h>
#include <string>

#define ERR_EXPLAIN(msg)
#define ERR_FAIL_COND(cond)
#define ERR_PRINTS(msg)

enum RPCMode {
    RPC_MODE_DISABLED
};

class StringName {};
class Variant {};
class ScriptInstance {
public:
    RPCMode get_rset_mode(const StringName &);
};

template<class K, class V>
class Map {
public:
    class Element {
    public:
        V get() const;
    };
};

class Node {
public:
    const Map<StringName, RPCMode>::Element* get_node_rset_mode(const StringName&);
    int get_network_master();
    const char* get_class();
    void set(const StringName&, const Variant&, bool*);
    ScriptInstance* get_script_instance();
};

class String {
public:
    String(const StringName&);
    String(const char*);
    String operator+(const String&) const;
    friend String operator+(const char*, const String&);
};

class Error {
public:
    enum { OK = 0 };
};

class NetworkPeer {
public:
    bool is_object_decoding_allowed();
};

class MultiplayerAPI {
public:
    bool _can_call_mode(Node*, RPCMode, int);
    NetworkPeer* network_peer;
    void _process_rset(Node*, const StringName&, int, const uint8_t*, int, int);
};

Error decode_variant(Variant&, const uint8_t*, int, void*, bool);
Error decode_variant(Variant&, const uint8_t*, int);

String itos(int);