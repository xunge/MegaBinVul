struct key_preparsed_payload {
    union {
        void *data[2];
    } payload;
};

struct rxrpc_security {
    void (*free_preparse_server_key)(struct key_preparsed_payload *prep);
};