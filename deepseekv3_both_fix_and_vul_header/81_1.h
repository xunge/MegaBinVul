#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#define CMD_RET_USAGE 1
#define DEFAULT_ADDR_LEN 1
#define I2C_ERR_WRITE 1
#define CONFIG_IS_ENABLED(x) 0
#define CONFIG_SYS_I2C_FRAM 0

typedef unsigned long ulong;
typedef unsigned char uchar;
typedef unsigned int uint;

struct cmd_tbl;
struct udevice;

unsigned long hextoul(const char *str, char **endptr);
int get_alen(const char *s, int default_len);
int i2c_report_err(int ret, int err);
int i2c_get_cur_bus_chip(uint chip, struct udevice **dev);
int i2c_set_chip_offset_len(struct udevice *dev, int alen);
int dm_i2c_write(struct udevice *dev, ulong addr, uchar *byte, int len);
int i2c_write(uint chip, ulong addr, int alen, uchar *byte, int len);
void udelay(unsigned long usec);