#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <sys/prctl.h>
#include <sys/socket.h>
#include <signal.h>
#include <sched.h>
#include <errno.h>
#include <linux/capability.h>
#include <stdbool.h>
#include <sys/sysmacros.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/sched.h>

#define LIBDIR "/usr/lib"
#define RUN_FIREJAIL_LIB_DIR "/run/firejail/lib"
#define RUN_ETC_DIR "/run/firejail/etc"
#define RUN_OPT_DIR "/run/firejail/opt"
#define RUN_SRV_DIR "/run/firejail/srv"
#define PATH_FNET "/usr/bin/fnet"
#define RUN_SECCOMP_PROTOCOL "/run/firejail/seccomp/protocol"
#define RUN_SECCOMP_MDWX "/run/firejail/seccomp/mdwx"
#define RUN_SECCOMP_CFG "/run/firejail/seccomp/seccomp.cfg"
#define RUN_SECCOMP_32 "/run/firejail/seccomp/seccomp.32"

#define SBOX_ROOT 0x01
#define SBOX_CAPS_NETWORK 0x02
#define SBOX_SECCOMP 0x04
#define SBOX_USER 0x08
#define SBOX_CAPS_NONE 0x10

#define CFG_DISABLE_MNT 1
#define CLONE_NEWUSER 0x10000000

struct config {
    char *hostname;
    char *name;
    char *chrootdir;
    char *protocol;
    char *seccomp_list;
    char *seccomp_list_drop;
    char *seccomp_list_keep;
    char *dns1;
    char *dns2;
    char *dns3;
    char *dns4;
    char *hosts_file;
    char *homedir;
    char *cwd;
    char *bin_private_keep;
    char *etc_private_keep;
    char *opt_private_keep;
    char *srv_private_keep;
    unsigned int defaultgw;
    unsigned int ip;
    unsigned int mask;
    unsigned int mtu;
    int cpus;
    int nice;
    int configured;
    int home_private;
    int home_private_keep;
    char *dev;
    char *macsandbox;
    char *devsandbox;
    struct {
        char *macsandbox;
        char *devsandbox;
    } bridge0, bridge1, bridge2, bridge3;
    struct {
        int configured;
        unsigned int ip;
        unsigned int mask;
        unsigned int mtu;
        char *dev;
    } interface0, interface1, interface2, interface3;
};

extern struct config cfg;

extern int arg_debug;
extern int arg_nonetwork;
extern char *arg_netns;
extern int arg_quiet;
extern int arg_scan;
extern int arg_nodbus;
extern int arg_nosound;
extern int arg_noautopulse;
extern int arg_no3d;
extern int arg_notv;
extern int arg_nodvd;
extern int arg_nou2f;
extern int arg_novideo;
extern int arg_trace;
extern int arg_tracelog;
extern int arg_seccomp;
extern int arg_seccomp_postexec;
extern int arg_appimage;
extern int arg_overlay;
extern int arg_private;
extern int arg_private_dev;
extern int arg_private_etc;
extern int arg_private_opt;
extern int arg_private_srv;
extern int arg_private_bin;
extern int arg_private_lib;
extern int arg_private_cache;
extern int arg_private_tmp;
extern int arg_disable_mnt;
extern int arg_x11_xorg;
extern int arg_noroot;
extern int arg_nogroups;
extern int arg_nonewprivs;
extern int force_nonewprivs;
extern int arg_memory_deny_write_execute;
extern int arg_netfilter;
extern char *arg_netfilter_file;
extern int arg_netfilter6;
extern char *arg_netfilter6_file;
extern int arg_nice;
extern int sandbox_pid;
extern int parent_to_child_fds[2];
extern int child_to_parent_fds[2];

#define PRINT_IP(ip) ((ip)>>24)&0xff, ((ip)>>16)&0xff, ((ip)>>8)&0xff, (ip)&0xff

void errExit(const char *msg);
void fwarning(const char *fmt, ...);
void fmessage(const char *fmt, ...);
void wait_for_other(int fd);
void notify_other(int fd);
void chk_chroot(void);
void preproc_mount_mnt_dir(void);
void fs_logger2(const char *prefix, const char *str);
void fs_logger2int(const char *prefix, int num);
void fs_logger(const char *str);
int any_bridge_configured(void);
int any_interface_configured(void);
void netfilter(const char *file);
void netfilter6(const char *file);
void net_if_up(const char *iface);
void netns(const char *name);
int mac_not_zero(const char *mac);
void net_config_mac(const char *iface, const char *mac);
void sandbox_if_up(struct config *cfg);
void net_config_interface(const char *iface, unsigned int ip, unsigned int mask, unsigned int mtu);
int net_add_route(unsigned int net, unsigned int mask, unsigned int gw);
void sbox_run(int flags, int argc, ...);
void EUID_USER(void);
void EUID_ROOT(void);
void env_ibus_load(void);
void enforce_filters(void);
void fs_trace_preload(void);
void fs_store_hosts_file(void);
void fs_chroot(const char *dir);
void fs_overlayfs(void);
void fs_basic_fs(void);
void fs_private_homedir(void);
void fs_private_home_list(void);
void fs_private(void);
void fs_private_dev(void);
void fs_private_dir_list(const char *dir, const char *run_dir, const char *keep);
void fs_private_bin_list(void);
void fs_private_lib(void);
void fs_private_cache(void);
void fs_private_tmp(void);
void dbus_session_disable(void);
void fs_hostname(const char *hostname);
void fs_mount_hosts_file(void);
void netns_mounts(const char *name);
void fs_proc_sys_dev_boot(void);
void fs_mnt(int disable);
void fs_whitelist(void);
void fs_blacklist(void);
void pulseaudio_disable(void);
void fs_dev_disable_sound(void);
void pulseaudio_init(void);
void fs_dev_disable_3d(void);
void fs_dev_disable_tv(void);
void fs_dev_disable_dvd(void);
void fs_dev_disable_u2f(void);
void fs_dev_disable_video(void);
void fs_trace(void);
void fs_resolvconf(void);
void fs_logger_print(void);
void fs_logger_change_owner(void);
void fs_x11(void);
void x11_xorg(void);
void save_umask(void);
void save_nonewprivs(void);
void set_caps(void);
void save_cpu(void);
void save_cgroup(void);
void seccomp_load(const char *file);
void protocol_filter_save(void);
void seccomp_filter_keep(void);
void seccomp_filter_drop(void);
void save_nogroups(void);
void drop_privs(int nogroups);
void set_cpu_affinity(void);
void set_nice(int nice);
void set_rlimits(void);
void start_application(int argc, FILE *rj);
int monitor_application(pid_t pid);
void flush_stdin(void);
FILE *create_ready_for_join_file(void);