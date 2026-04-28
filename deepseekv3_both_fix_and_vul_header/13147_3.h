#include <string>

using std::string;

struct TensorArray;
struct ResourceMgr;

enum DataType {
    DT_RESOURCE
};

class Status {
public:
    static Status OK();
    bool ok() const;
};

struct OpKernelContext {
    DataType input_dtype(int);
    ResourceMgr* resource_manager();
    struct ScopedStepContainer* step_container();
};

struct ScopedStepContainer {
    Status Lookup(ResourceMgr*, const string&, TensorArray**);
};

Status OkStatus();
Status GetHandle(OpKernelContext*, string*, string*);
Status LookupResource(OpKernelContext*, void*, TensorArray**);
void* HandleFromInput(OpKernelContext*, int);

#define TF_RETURN_IF_ERROR(expr) \
    do { \
        Status _status = (expr); \
        if (!_status.ok()) return _status; \
    } while (0)

namespace errors {
    Status Internal(const char* msg);
}