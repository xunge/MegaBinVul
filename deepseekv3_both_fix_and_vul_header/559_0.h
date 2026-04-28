#include <stdint.h>

#define I2C_SMBUS_BLOCK_MAX 32
#define I2C_SMBUS_READ 1
#define I2C_SMBUS_WRITE 0
#define I2C_M_RD 0x0001
#define I2C_M_RECV_LEN 0x0400
#define I2C_CLIENT_PEC 0x04

#define EINVAL 22
#define EOPNOTSUPP 95

typedef int32_t s32;
typedef uint16_t u16;
typedef uint8_t u8;

struct i2c_msg {
    u16 addr;
    u16 flags;
    u16 len;
    u8 *buf;
};

struct i2c_adapter {
    int dev;
};

union i2c_smbus_data {
    u8 byte;
    u16 word;
    u8 block[I2C_SMBUS_BLOCK_MAX + 2];
};

enum i2c_smbus_size {
    I2C_SMBUS_QUICK,
    I2C_SMBUS_BYTE,
    I2C_SMBUS_BYTE_DATA,
    I2C_SMBUS_WORD_DATA,
    I2C_SMBUS_PROC_CALL,
    I2C_SMBUS_BLOCK_DATA,
    I2C_SMBUS_BLOCK_PROC_CALL,
    I2C_SMBUS_I2C_BLOCK_DATA
};

static void i2c_smbus_add_pec(struct i2c_msg *msg);
static u8 i2c_smbus_msg_pec(u8 pec, struct i2c_msg *msg);
static int i2c_smbus_check_pec(u8 pec, struct i2c_msg *msg);
static int i2c_transfer(struct i2c_adapter *adapter, struct i2c_msg *msgs, int num);