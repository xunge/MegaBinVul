#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>

#define L2CAP_MIN_OFFSET 0
#define GATT_RSP_READ_MULTI_VAR 0
#define GATT_RSP_READ_MULTI 0
#define GATT_NOT_FOUND 0

typedef struct {
    uint16_t offset;
    uint16_t len;
} BT_HDR;

typedef struct {
    struct {
        uint16_t handle;
        uint16_t len;
        uint8_t* value;
    } attr_value;
} tGATTS_RSP;

typedef struct tGATT_MULTI_REQ {
    bool variable_len;
    uint16_t num_handles;
    uint16_t* handles;
} tGATT_MULTI_REQ;

typedef struct {
    tGATT_MULTI_REQ multi_req;
    void* multi_rsp_q;
    void* p_rsp_msg;
    int status;
} tGATT_SR_CMD;

typedef struct list_node_t list_node_t;
typedef struct list_t list_t;

void* osi_calloc(size_t size);
void osi_free(void* ptr);
bool fixed_queue_is_empty(void* queue);
list_t* fixed_queue_get_list(void* queue);
const list_node_t* list_begin(const list_t* list);
const list_node_t* list_next(const list_node_t* node);
const list_node_t* list_end(const list_t* list);
void* list_node(const list_node_t* node);

#define VLOG(level) if (0) std::cout
#define LOG(level) if (0) std::cout

class StringPrintf {
public:
    StringPrintf(const char* fmt, ...) {}
    friend std::ostream& operator<<(std::ostream& os, const StringPrintf& sp) {
        return os;
    }
};

#define UINT16_TO_STREAM(p, u16) \
    do { \
        *(p)++ = (uint8_t)(u16); \
        *(p)++ = (uint8_t)((u16) >> 8); \
    } while (0)

#define ARRAY_TO_STREAM(p, array, len) \
    do { \
        memcpy((p), (array), (len)); \
        (p) += (len); \
    } while (0)