typedef unsigned long VALUE;

typedef struct _agooReq {
    void *env;
} *agooReq;

typedef struct {
    int rack_early_hints;
} agooServer;

extern agooServer agoo_server;

#define Qnil 0
#define Qfalse 0
#define Qtrue 1

extern VALUE request_method_val;
extern VALUE script_name_val;
extern VALUE path_info_val;
extern VALUE query_string_val;
extern VALUE remote_addr_val;
extern VALUE server_port_val;
extern VALUE server_name_val;
extern VALUE rack_version_val;
extern VALUE rack_url_scheme_val;
extern VALUE rack_input_val;
extern VALUE rack_errors_val;
extern VALUE rack_multithread_val;
extern VALUE rack_multiprocess_val;
extern VALUE rack_run_once_val;
extern VALUE rack_logger_val;
extern VALUE rack_upgrade_val;
extern VALUE rack_hijackq_val;
extern VALUE rack_hijack_val;
extern VALUE rack_hijack_io_val;
extern VALUE early_hints_val;
extern VALUE rack_version_val_val;

VALUE rb_hash_new();
void rb_hash_aset(VALUE hash, VALUE key, VALUE val);

VALUE req_method(agooReq req);
VALUE req_script_name(agooReq req);
VALUE req_path_info(agooReq req);
VALUE req_query_string(agooReq req);
VALUE req_remote_addr(agooReq req);
VALUE req_server_port(agooReq req);
VALUE req_server_name(agooReq req);
VALUE req_rack_url_scheme(agooReq req);
VALUE req_rack_input(agooReq req);
VALUE req_rack_errors(agooReq req);
VALUE req_rack_multithread(agooReq req);
VALUE req_rack_logger(agooReq req);
VALUE req_rack_upgrade(agooReq req);
void fill_headers(agooReq req, VALUE env);
VALUE agoo_early_hints_new(agooReq req);