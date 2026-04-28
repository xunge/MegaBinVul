#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <linux/limits.h>
#include <getopt.h>

#define CONFIG_FILE 1
#define HAVE_GETPWUID 1
#define LONG_OPTIONS 1
#define PROC_NET_DEV 1
#define PROC_DISKSTATS 1
#define NETSTAT 1
#define ALLOW_NETSTATPATH 1
#define IOSERVICE_IN 1
#define EXTENDED_STATS 1
#define CSV 1
#define HTML 1
#define AVG_LENGTH 1000

#define SHORT_OPTIONS "t:f:n:i:d:hVa:u:NT:A:I:S:o:c:D:R:H:F:C:"

enum {
    BYTES_OUT,
    PACKETS_OUT, 
    ERRORS_OUT
};

enum {
    LIBSTATDISK_IN
};

extern char *optarg;
extern int optind, opterr;
extern int show_all_if;
extern int dynamic;
extern int daemonize;
extern int html_header;
extern long html_refresh;
extern int sumhidden;
extern char PROC_DISKSTATS_FILE[PATH_MAX];
extern char PROC_PARTITIONS_FILE[PATH_MAX];
extern int long_darwin_disk_names;
extern long output_count;
extern FILE *out_file;
extern char *out_file_path;
extern char csv_char;
extern char *iface_list;
extern int input_method;
extern int output_method;
extern int ansi_output;
extern long delay;
extern int output_type;
extern long avg_length;
extern int output_unit;
extern char NETSTAT_FILE[PATH_MAX];
extern char PROC_FILE[PATH_MAX];

void read_config(char *filename);
void deinit(int status, char *message);
void cmdln_printhelp(void);
int str2in_method(char *str);
int str2out_method(char *str);
int str2output_type(char *str);
int str2output_unit(char *str);
int net_input_method(int method);
void print_version(void);