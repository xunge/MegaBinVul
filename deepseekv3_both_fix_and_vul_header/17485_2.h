struct key {
    struct {
        void *data[2];
    } payload;
};

struct rxrpc_security {
    void (*destroy_server_key)(struct key *key);
};