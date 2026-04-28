#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

#define GATT_MAX_ATTR_LEN 512
#define GATT_WRITE_PREPARE 5
#define WARNING 1

using namespace std;

class Logger {
public:
    Logger& operator<<(const char* str) {
        printf("%s", str);
        return *this;
    }
    Logger& operator<<(int num) {
        printf("%d", num);
        return *this;
    }
};

Logger VLOG(int level);
Logger LOG(int level);

typedef enum {
  GATT_SUCCESS = 0,
  GATT_INVALID_HANDLE,
  GATT_READ_NOT_PERMITTED,
  GATT_WRITE_NOT_PERMITTED,
  GATT_INVALID_PDU,
  GATT_INSUFFICIENT_AUTHENTICATION,
  GATT_REQUEST_NOT_SUPPORTED,
  GATT_INVALID_OFFSET,
  GATT_INSUFFICIENT_AUTHORIZATION,
  GATT_PREPARE_QUEUE_FULL,
  GATT_ATTRIBUTE_NOT_FOUND,
  GATT_NOT_LONG,
  GATT_INSUFFICIENT_KEY_SIZE,
  GATT_INVALID_ATTRIBUTE_LENGTH,
  GATT_ERROR_UNLIKELY,
  GATT_INSUFFICIENT_ENCRYPTION,
  GATT_UNSUPPORTED_GROUP_TYPE,
  GATT_INSUFFICIENT_RESOURCES,
  GATT_DATABASE_OUT_OF_SYNC,
  GATT_VALUE_NOT_ALLOWED,
  GATT_NO_RESOURCES,
  GATT_INTERNAL_ERROR,
  GATT_WRONG_STATE,
  GATT_DB_FULL,
  GATT_BUSY,
  GATT_ERROR,
  GATT_CMD_STARTED,
  GATT_ILLEGAL_PARAMETER,
  GATT_PENDING,
  GATT_AUTH_FAIL,
  GATT_MORE,
  GATT_INVALID_CFG,
  GATT_SERVICE_STARTED,
  GATT_ENCRYPTED_MITM,
  GATT_ENCRYPTED_NO_MITM,
  GATT_NOT_ENCRYPTED,
  GATT_CONGESTED,
  GATT_DUP_REG,
  GATT_ALREADY_OPEN,
  GATT_CANCEL
} tGATT_STATUS;

typedef enum {
  GATTC_OPTYPE_NONE,
  GATTC_OPTYPE_READ,
  GATTC_OPTYPE_WRITE,
  GATTC_OPTYPE_EXE_WRITE,
  GATTC_OPTYPE_CONFIG,
  GATTC_OPTYPE_DISCOVERY,
  GATTC_OPTYPE_NOTIFICATION,
  GATTC_OPTYPE_INDICATION
} tGATTC_OPTYPE;

typedef enum {
  GATT_DISC_SRVC_ALL = 1,
  GATT_DISC_SRVC_BY_UUID,
  GATT_DISC_INC_SRVC,
  GATT_DISC_CHAR,
  GATT_DISC_CHAR_DSCPT,
  GATT_DISC_MAX
} tGATT_DISC_TYPE;

typedef struct {
  uint16_t handle;
  uint16_t len;
  uint8_t value[GATT_MAX_ATTR_LEN];
} tGATT_VALUE;

typedef struct {
  tGATT_VALUE att_value;
  uint16_t handle;
  uint16_t mtu;
} tGATT_CL_COMPLETE;

typedef void (*tGATT_CMPL_CBACK)(uint16_t conn_id, tGATTC_OPTYPE op, tGATT_STATUS status, tGATT_CL_COMPLETE* p_data);
typedef void (*tGATT_DISC_CMPL_CB)(uint16_t conn_id, tGATT_DISC_TYPE disc_type, tGATT_STATUS status);

typedef struct {
  tGATT_CMPL_CBACK* p_cmpl_cb;
  tGATT_DISC_CMPL_CB* p_disc_cmpl_cb;
} tGATT_CL_APP_CB;

typedef struct {
  tGATT_CL_APP_CB app_cb;
} tGATT_REGISTER;

typedef struct {
  uint16_t payload_size;
} tGATT_TCB;

typedef struct {
  tGATT_REGISTER* p_reg;
  tGATTC_OPTYPE operation;
  uint8_t op_subtype;
  uint16_t s_handle;
  uint16_t counter;
  tGATT_TCB* p_tcb;
  uint16_t conn_id;
  void* p_attr_buf;
} tGATT_CLCB;

void osi_free_and_reset(void** ptr);
void gatt_stop_rsp_timer(tGATT_CLCB* p_clcb);
void gatt_clcb_dealloc(tGATT_CLCB* p_clcb);
char* StringPrintf(const char* fmt, ...);