#include <stdio.h>
#include <stdint.h>

#define CMD_RET_USAGE 1
#define DEFAULT_ADDR_LEN 1
#define CONFIG_IS_ENABLED(x) 0
#define I2C_ERR_READ 1

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;

struct cmd_tbl;
struct udevice;

extern unsigned long hextoul(const char *str, char **endp);
extern int get_alen(const char *arg, int default_len);
extern int i2c_get_cur_bus_chip(uint chip, struct udevice **dev);
extern int i2c_set_chip_offset_len(struct udevice *dev, int alen);
extern int i2c_report_err(int ret, int err);
extern int dm_i2c_read(struct udevice *dev, ulong addr, uchar *byte, int len);
extern int i2c_read(uint chip, ulong addr, int alen, uchar *buffer, int len);
extern ulong crc32(ulong crc, const uchar *buf, uint len);