#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct MIMEField MIMEField;
typedef struct INKVConnInternal INKVConnInternal;

struct HTTPVersion {
    HTTPVersion(int, int);
    bool operator==(const HTTPVersion&) const;
};

struct HttpTransact {
    enum RangeSetup {
        RANGE_NONE,
        RANGE_REQUESTED,
        RANGE_NOT_TRANSFORM_REQUESTED,
        RANGE_NOT_SATISFIABLE
    };
    enum CacheLookupResult {
        CACHE_LOOKUP_MISS
    };
};

struct HttpTxnConf {
    int allow_multi_range;
};

struct Response {
    const char *(*value_get)(int, int, int*);
    uint64_t (*object_size_get)();
};

struct CacheObjectRead {
    Response *(*response_get)();
    uint64_t (*object_size_get)();
};

struct CacheInfo {
    CacheObjectRead *object_read;
};

struct ClientRequest {
    HTTPVersion (*version_get)();
    MIMEField *(*field_find)(int, int);
    void (*field_delete)(int, int);
};

struct HdrInfo {
    ClientRequest client_request;
    void *transform_response;
};

struct CacheSM {
    struct {
        struct {
            bool (*is_pread_capable)();
        } *cache_read_vc;
    };
};

struct APIHooks {
    void *(*get)(int);
    void (*append)(int, INKVConnInternal*);
};

struct TransformProcessor {
    INKVConnInternal *(*range_transform)(void*, void*, int, void*, const char*, int, uint64_t);
};

struct HttpSM {
    struct State {
        CacheInfo cache_info;
        int cache_lookup_result;
        bool range_in_cache;
        int method;
        HdrInfo hdr_info;
        int range_setup;
        int num_range_fields;
        void *ranges;
        HttpTxnConf *txn_conf;
    } t_state;
    CacheSM cache_sm;
    APIHooks api_hooks;
    TransformProcessor transformProcessor;
    struct {
        void *(*get)();
    } mutex;
    void do_range_setup_if_necessary();
    void do_range_parse(MIMEField*);
};

enum {
    HTTP_WKSIDX_GET,
    MIME_FIELD_RANGE,
    MIME_LEN_RANGE,
    MIME_FIELD_CONTENT_TYPE,
    MIME_LEN_CONTENT_TYPE,
    TS_HTTP_RESPONSE_TRANSFORM_HOOK
};

extern void ink_assert(bool);
extern void Debug(const char*, const char*);