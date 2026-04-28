#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <map>
#include <vector>

class NetVC {
public:
    struct sockaddr* get_local_addr();
    bool get_is_internal_request();
};

class HttpSM;

class Transaction {
public:
    NetVC* get_netvc();
};

class HttpSM {
public:
    Transaction* ua_txn;
    NetVC* get_netvc() { return ua_txn->get_netvc(); }
};

class StateMachine {
public:
    HttpSM* ua_txn;
};

class HttpTransact {
public:
    class State {
    public:
        bool acl_filtering_performed;
        bool client_connection_enabled;
        struct {
            class ClientRequest {
            public:
                int method_get_wksidx();
                const char* method_get(int* len);
            } client_request;
        } hdr_info;
        struct {
            struct sockaddr_storage src_addr;
        } client_info;
        StateMachine* state_machine;
    };
};

class IpEndpoint {
public:
    void assign(const struct sockaddr* addr);
};

class acl_filter_rule {
public:
    acl_filter_rule* next;
    bool method_restriction_enabled;
    bool* standard_method_lookup;
    std::map<std::string, bool> nonstandard_methods;
    bool src_ip_valid;
    int src_ip_cnt;
    struct {
        struct sockaddr_storage start;
        struct sockaddr_storage end;
        bool invert;
        bool contains(const struct sockaddr_storage& addr);
    } *src_ip_array;
    bool in_ip_valid;
    int in_ip_cnt;
    struct {
        struct sockaddr_storage start;
        struct sockaddr_storage end;
        bool invert;
        bool contains(const IpEndpoint& addr);
    } *in_ip_array;
    bool internal;
    bool allow_flag;
};

class url_mapping {
public:
    acl_filter_rule* filter;
};

class UrlRewrite {
public:
    void PerformACLFiltering(HttpTransact::State *s, url_mapping *map);
};

#define HTTP_WKSIDX_CONNECT 0
#define HTTP_WKSIDX_METHODS_CNT 10
#define unlikely(x) (x)
#define Debug(tag, ...)
#define is_debug_tag_set(tag) false
#define ats_is_ip(addr) true
#define ats_ip_ntop(addr, buf, len)
#define ink_release_assert(expr)