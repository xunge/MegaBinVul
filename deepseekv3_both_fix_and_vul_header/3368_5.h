#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define COMEDI_VERSION_CODE 0
#define COMEDI_NAMELEN 20
#define EFAULT 14

struct comedi_devinfo {
    unsigned int version_code;
    unsigned int n_subdevs;
    char driver_name[COMEDI_NAMELEN];
    char board_name[COMEDI_NAMELEN];
    int read_subdevice;
    int write_subdevice;
};

struct comedi_device {
    unsigned int n_subdevices;
    struct {
        char *driver_name;
    } *driver;
    char *board_name;
    struct comedi_subdevice *subdevices;
};

struct comedi_subdevice {
    int dummy;  // 添加至少一个成员使结构体完整
};

struct comedi_device_file_info;
struct file {
    struct dentry *f_dentry;
};
struct inode;
struct dentry {
    struct inode *d_inode;
};

#define __user

unsigned iminor(struct inode *inode);
struct comedi_device_file_info *comedi_get_device_file_info(unsigned minor);
struct comedi_subdevice *comedi_get_read_subdevice(struct comedi_device_file_info *info);
struct comedi_subdevice *comedi_get_write_subdevice(struct comedi_device_file_info *info);
int copy_to_user(void *to, const void *from, unsigned long n);