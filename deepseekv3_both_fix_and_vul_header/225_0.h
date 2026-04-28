#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <unistd.h>

extern int tmpfs_mounted;
extern int arg_debug;
extern int arg_seccomp_block_secondary;
extern int arg_allow_debuggers;
extern int arg_memory_deny_write_execute;
extern char* RUN_MNT_DIR;
extern char* PATH_SECCOMP_BLOCK_SECONDARY;
extern char* RUN_SECCOMP_BLOCK_SECONDARY;
extern char* PATH_SECCOMP_32;
extern char* RUN_SECCOMP_32;
extern char* PATH_SECCOMP_DEFAULT_DEBUG;
extern char* RUN_SECCOMP_CFG;
extern char* PATH_SECCOMP_DEFAULT;
extern char* PATH_SECCOMP_MDWX;
extern char* RUN_SECCOMP_MDWX;
extern char* RUN_SECCOMP_PROTOCOL;
extern char* RUN_SECCOMP_POSTEXEC;

void errExit(const char* msg);
void fs_logger2(const char* str1, const char* str2);
void copy_file(const char* src, const char* dest, uid_t uid, gid_t gid, mode_t mode);
void create_empty_file_as_root(const char* fname, mode_t mode);
int set_perms(const char* fname, uid_t uid, gid_t gid, mode_t mode);