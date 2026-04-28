#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>

#define SEATD_VERSION "0.1.0"
#define SEATD_INSTALLPATH "/usr/bin/seatd"

extern char *optarg;
extern int optind, opterr, optopt;