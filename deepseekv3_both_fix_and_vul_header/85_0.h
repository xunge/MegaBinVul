#include <stdint.h>
#include <stdlib.h>

#define CMD_RET_USAGE 1
#define DEFAULT_ADDR_LEN 1
#define CONFIG_IS_ENABLED(x) 0
#define I2C_ERR_READ 0

struct cmd_tbl;
struct udevice;

typedef unsigned char u_char;

unsigned long hextoul(const char *str, char **endp);
int get_alen(const char *arg, int default_len);
int i2c_get_cur_bus_chip(uint chip, struct udevice **dev);
int i2c_set_chip_offset_len(struct udevice *dev, int alen);
int dm_i2c_read(struct udevice *dev, uint devaddr, u_char *memaddr, uint length);
int i2c_read(uint chip, uint devaddr, int alen, u_char *memaddr, uint length);
int i2c_report_err(int ret, int err_type);