#include <stdbool.h>

typedef struct {
    const char* node_name;
    const char* (*node)();
} TensorId;

typedef struct NodeDef {
    int input_size_value;
    const char** inputs;
    int (*input_size)();
    const char* (*input)(int index);
} NodeDef;

typedef struct MutableGraphView {
    NodeDef* (*GetNode)(const char* node);
} MutableGraphView;

TensorId ParseTensorName(const char* input);
bool IsIdentity(const NodeDef& node);
bool IsIdentityNSingleInput(const NodeDef& node);
bool IsTensorIdControlling(TensorId tensor_id);
bool IsSwitch(const NodeDef& node);