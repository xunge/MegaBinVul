#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <shadow.h>
#include <crypt.h>

#define PCAP_ERRBUF_SIZE 256
#define LOGPRIO_ERROR 0

extern void rpcapd_log(int priority, const char *format, ...);
extern void pcap_fmt_errmsg_for_win32_err(char *, size_t, unsigned long, const char *);
extern void pcap_fmt_errmsg_for_errno(char *, size_t, int, const char *);
extern int pcap_snprintf(char *str, size_t sz, const char *format, ...);

typedef void* HANDLE;
typedef unsigned long DWORD;