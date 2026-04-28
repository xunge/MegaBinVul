#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define MAX_MESSAGE_LENGTH 256
#define MODBUS_FC_READ_COILS 0x01
#define MODBUS_FC_READ_DISCRETE_INPUTS 0x02
#define MODBUS_FC_READ_HOLDING_REGISTERS 0x03
#define MODBUS_FC_READ_INPUT_REGISTERS 0x04
#define MODBUS_FC_WRITE_SINGLE_COIL 0x05
#define MODBUS_FC_WRITE_SINGLE_REGISTER 0x06
#define MODBUS_FC_WRITE_MULTIPLE_COILS 0x0F
#define MODBUS_FC_WRITE_MULTIPLE_REGISTERS 0x10
#define MODBUS_FC_REPORT_SLAVE_ID 0x11
#define MODBUS_FC_READ_EXCEPTION_STATUS 0x07
#define MODBUS_FC_MASK_WRITE_REGISTER 0x16
#define MODBUS_FC_WRITE_AND_READ_REGISTERS 0x17

#define MODBUS_EXCEPTION_ILLEGAL_FUNCTION 0x01
#define MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS 0x02
#define MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE 0x03
#define MODBUS_MAX_READ_BITS 0x7D0
#define MODBUS_MAX_READ_REGISTERS 0x7D
#define MODBUS_MAX_WRITE_BITS 0x7B0
#define MODBUS_MAX_WRITE_REGISTERS 0x7B
#define MODBUS_MAX_WR_WRITE_REGISTERS 0x79
#define MODBUS_MAX_WR_READ_REGISTERS 0x7D
#define MODBUS_BROADCAST_ADDRESS 0
#define _MODBUS_BACKEND_TYPE_RTU 0
#define _REPORT_SLAVE_ID 0x00
#define LIBMODBUS_VERSION_STRING "3.1.6"

#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

typedef struct {
    int slave;
    int function;
    int t_id;
} sft_t;

typedef struct {
    int backend_type;
    int (*prepare_response_tid)(const uint8_t *req, int *req_length);
    int (*build_response_basis)(sft_t *sft, uint8_t *rsp);
    int header_length;
} modbus_backend_t;

typedef struct {
    int start_bits;
    int nb_bits;
    uint8_t *tab_bits;
    int start_input_bits;
    int nb_input_bits;
    uint8_t *tab_input_bits;
    int start_registers;
    int nb_registers;
    uint16_t *tab_registers;
    int start_input_registers;
    int nb_input_registers;
    uint16_t *tab_input_registers;
} modbus_mapping_t;

typedef struct {
    modbus_backend_t *backend;
    int debug;
} modbus_t;

int response_exception(modbus_t *ctx, sft_t *sft, int exception_code, uint8_t *rsp, int flush, const char *format, ...);
int response_io_status(uint8_t *tab_bits, int address, int nb, uint8_t *rsp, int rsp_length);
void modbus_set_bits_from_bytes(uint8_t *dest, int idx, int nb_bits, const uint8_t *tab_byte);
int send_msg(modbus_t *ctx, const uint8_t *msg, int msg_length);