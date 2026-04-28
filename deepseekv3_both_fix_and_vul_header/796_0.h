#include <stdio.h>
#include <errno.h>
#include <stddef.h>

#define PCAP_ERRBUF_SIZE 256
#define PRIsize "zu"

int pcap_fmt_errmsg_for_errno(char *, size_t, int, const char *);
int pcap_snprintf(char *, size_t, const char *, ...);