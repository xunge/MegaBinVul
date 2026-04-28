#include <string>
#include <typeinfo>
#include <iostream>
#include <iomanip>

#define ERR_METHOD_NOT_ALLOWED 405
#define ERR_USER_SUSPENDED 403

struct RGWRados;
struct rgw_auth_registry_t;
struct RGWRestfulIO;
struct OpsLogSocket;
struct RGWEnv;
struct RGWUserInfo;
struct req_state;
struct RGWObjectCtx;
struct RGWOp;
struct RGWRESTMgr;
struct RGWHandler_REST;
struct rgw_log_op;

#define dout(level) std::cout
#define hex std::hex
#define dec std::dec
#define dendl std::endl

extern RGWRados* g_ceph_context;
extern rgw_log_op* perfcounter;
extern int l_rgw_req;

struct RGWRequest {
    void log_init();
    void log_format(req_state* s, const char* fmt, ...);
    void log(req_state* s, const char* msg);
    std::string id;
    RGWOp* op;
};

struct RGWRados {
    std::string unique_id(const std::string& id);
    std::string unique_trans_id(const std::string& id);
    std::string host_id;
};

struct RGWREST {
    RGWHandler_REST* get_handler(RGWRados* store, req_state* s,
                               const rgw_auth_registry_t& auth_registry,
                               const std::string& frontend_prefix,
                               RGWRestfulIO* client_io,
                               RGWRESTMgr** mgr,
                               int* init_error);
    void put_handler(RGWHandler_REST* handler);
};

struct rgw_log_op {
    void inc(int counter);
};

struct RGWUserInfo {
    bool suspended;
    std::string user_id;
};

struct req_state {
    void* obj_ctx;
    std::string req_id;
    std::string trans_id;
    std::string host_id;
    int op;
    std::string op_type;
    struct {
        void* identity;
    } auth;
    struct {
        int http_ret;
        int ret;
    } err;
    RGWUserInfo* user;
    RGWRestfulIO* cio;
    req_state(void* ctx, RGWEnv* env, RGWUserInfo* info);
};

struct RGWObjectCtx {
    RGWObjectCtx(RGWRados* store, req_state* s);
};

class RGWOp {
public:
    virtual int verify_requester(const rgw_auth_registry_t& auth_registry) = 0;
    virtual const char* name() const = 0;
    virtual int get_ret() const = 0;
    virtual std::string get_type() const = 0;
};

class RGWRESTMgr {
public:
    virtual bool get_logging() = 0;
};

class RGWHandler_REST {
public:
    virtual RGWOp* get_op(RGWRados* store) = 0;
    virtual int postauth_init() = 0;
    virtual void put_op(RGWOp* op) = 0;
};

class RGWRestfulIO {
public:
    virtual int init(void* ctx) = 0;
    virtual RGWEnv& get_env() = 0;
    virtual void complete_request() = 0;
};

namespace rgw {
namespace auth {
    void* transform_old_authinfo(req_state* s);
}
namespace io {
    class Exception {
    public:
        virtual const char* what() const noexcept = 0;
    };
}
}

int rgw_process_authenticated(RGWHandler_REST* handler, RGWOp* op, RGWRequest* req, req_state* s);
void abort_early(req_state* s, RGWOp* op, int ret, RGWHandler_REST* handler);
void rgw_log_op(RGWRados* store, RGWREST* rest, req_state* s, const char* op_name, OpsLogSocket* olog);