#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define CAP_SYS_RAWIO 0
#define X86_FEATURE_MSR 0

struct inode;
struct file {
    struct {
        struct {
            struct inode *d_inode;
        } *dentry;
    } f_path;
};

struct cpuinfo_x86 {
    unsigned long x86_capability[1];
};

static inline int capable(int cap) { return 0; }
static inline unsigned int iminor(struct inode *inode) { return 0; }
static inline int cpu_online(unsigned int cpu) { return 0; }
static inline struct cpuinfo_x86 *get_cpu_data(unsigned int cpu) { static struct cpuinfo_x86 c; return &c; }
static inline int cpu_has(struct cpuinfo_x86 *c, int feature) { return 0; }

extern unsigned int nr_cpu_ids;

#define cpu_data(cpu) (*get_cpu_data(cpu))