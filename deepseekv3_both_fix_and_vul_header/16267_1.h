#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <libgen.h>
#include <unistd.h>

#define LOCAL static
#define PACKAGE_VERSION "1.0.0"

extern char *optarg;
extern int optind, opterr, optopt;

void usage(char *program, int exit_code, const char *message);