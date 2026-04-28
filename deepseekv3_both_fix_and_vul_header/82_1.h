#include <stdint.h>
#include <stddef.h>

#define DEFAULT_ADDR_LEN 1
#define CMD_RET_USAGE 1
#define I2C_ERR_WRITE 1
#define I2C_ERR_READ 2
#define CONFIG_IS_ENABLED(x) 0

typedef unsigned int uint;
typedef unsigned char u_char;

struct cmd_tbl;
struct udevice;

unsigned int hextoul(const char *str, char **endp);
unsigned int dectoul(const char *str, char **endp);
int get_alen(const char *arg, int default_len);
int i2c_get_cur_bus_chip(uint chip, struct udevice **devp);
int i2c_set_chip_offset_len(struct udevice *dev, int alen);
int i2c_report_err(int ret, int err);
int dm_i2c_read(struct udevice *dev, uint addr, u_char *bytes, uint length);
int i2c_read(uint chip, uint addr, int alen, u_char *bytes, uint length);
void udelay(unsigned long usec);