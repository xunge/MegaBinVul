#include <stdint.h>
#include <string.h>

typedef unsigned int uint;
typedef unsigned char u_char;

struct cmd_tbl;
struct udevice;
struct dm_i2c_chip;

#define CONFIG_IS_ENABLED(x) 0
#define DEFAULT_ADDR_LEN 1
#define I2C_ERR_WRITE 0
#define DM_I2C_CHIP_WR_ADDRESS 0

unsigned long hextoul(const char *str, char **endp);
int cmd_usage(struct cmd_tbl *cmdtp);
int get_alen(const char *arg, int default_len);
int i2c_report_err(int ret, int err);
int i2c_get_cur_bus_chip(uint chip, struct udevice **dev);
int i2c_set_chip_offset_len(struct udevice *dev, int alen);
struct dm_i2c_chip *dev_get_parent_plat(struct udevice *dev);
int dm_i2c_write(struct udevice *dev, uint devaddr, u_char *memaddr, int length);
int i2c_write(uint chip, uint devaddr, int alen, u_char *memaddr, int length);
void udelay(unsigned long usec);