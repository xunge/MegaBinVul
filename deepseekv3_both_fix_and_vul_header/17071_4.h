typedef struct CephContext CephContext;

struct Env {
    void (*init)(CephContext* cct);
};

extern struct Env env;

#define override