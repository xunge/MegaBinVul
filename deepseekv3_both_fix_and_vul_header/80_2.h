#include <stdint.h>
#include <stdio.h>

#define CONFIG_IS_ENABLED(x) 0
#define DM_I2C 0
#define CMD_RET_USAGE 1
#define CMD_FLAG_REPEAT 0
#define DEFAULT_ADDR_LEN 1
#define DISP_LINE_LEN 16
#define I2C_ERR_READ 1

typedef unsigned int uint;

struct cmd_tbl;
struct udevice;

extern uint i2c_dp_last_chip;
extern uint i2c_dp_last_addr;
extern uint i2c_dp_last_alen;
extern uint i2c_dp_last_length;

unsigned long hextoul(const char *str, char **endp);
int get_alen(const char *arg, int default_len);
int i2c_get_cur_bus_chip(uint chip, struct udevice **devp);
int i2c_set_chip_offset_len(struct udevice *dev, int alen);
int i2c_report_err(int ret, int err);
int dm_i2c_read(struct udevice *dev, uint addr, unsigned char *buf, int len);
int i2c_read(uint chip, uint addr, int alen, unsigned char *buf, int len);

#define putc(c) putchar(c)