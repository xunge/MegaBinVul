#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <assert.h>

#define MAXBUF 4096
#define RUN_LIB_FILE "/run/firejail/mylib"
#define PATH_FLDD "/usr/bin/fldd"

#define SBOX_USER 0x01
#define SBOX_SECCOMP 0x02
#define SBOX_CAPS_NONE 0x04

extern int arg_debug;
extern int arg_debug_private_lib;

void errExit(const char *str);
void sbox_run(unsigned flags, int argc, ...);
void create_empty_file_as_root(const char *fname, mode_t mode);
void fslib_duplicate(const char *path);