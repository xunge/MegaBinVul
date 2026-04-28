#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <fcntl.h>

#define MODE_ENCODE 0
#define MODE_DECODE 1
#define MODE_TEST 2

#define KiB(n) ((n) * 1024)
#define MiB(n) ((n) * 1024 * 1024)

typedef unsigned int u32;

extern int optind;
extern char *optarg;

void help(void);
void version(void);
int is_numeric(const char *str);
FILE *open_input(const char *filename);
FILE *open_output(const char *filename, int force);
void close_out_file(FILE *file);
int process(FILE *input, FILE *output, int mode, u32 block_size, int workers, int verbose, const char *filename);