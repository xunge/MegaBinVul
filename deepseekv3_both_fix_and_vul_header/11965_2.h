#include <stdint.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdarg>

#define GATT_AUTH_REQ_NONE 0
#define GATT_INVALID_PDU 0
#define GATT_PREP_WRITE_RSP_MIN_LEN 4
#define GATT_WRITE_PREPARE 0
#define VLOG(level) std::cout
#define LOG(level) std::cout

struct tGATT_TCB {};
struct tGATT_CLCB {
    uint16_t conn_id;
    uint8_t op_subtype;
    uint8_t status;
};

struct tGATT_VALUE {
    uint16_t conn_id;
    uint8_t auth_req;
    uint16_t handle;
    uint16_t offset;
    uint16_t len;
    uint8_t value[1];
};

void gatt_end_operation(tGATT_CLCB* p_clcb, uint8_t status, tGATT_VALUE* p_value);
void gatt_send_prepare_write(tGATT_TCB& tcb, tGATT_CLCB* p_clcb);
bool gatt_check_write_long_terminate(tGATT_TCB& tcb, tGATT_CLCB* p_clcb, tGATT_VALUE* p_value);
const char* gatt_dbg_op_name(uint8_t op_code);

#define STREAM_TO_UINT16(u16, p) {u16 = ((uint16_t)(*(p)) + (((uint16_t)(*((p) + 1))) << 8)); (p) += 2;}

inline std::string StringPrintf(const char* format, ...) {
    char buf[256];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);
    return std::string(buf);
}