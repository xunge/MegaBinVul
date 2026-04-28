#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <libintl.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>

extern char *progname;
extern char *cmd_line_options;
extern int posixly_correct;
extern int print_options;
extern int opt_print_acl;
extern int opt_print_default_acl;
extern int opt_comments;
extern int walk_flags;
extern int opt_skip_base;
extern int opt_strip_leading_slash;
extern int opt_tabular;
extern int opt_numeric;
extern int had_errors;

#define POSIXLY_CORRECT_STR "POSIXLY_CORRECT"
#define POSIXLY_CMD_LINE_OPTIONS "dnhv"
#define CMD_LINE_OPTIONS "acdEeLPRstpnhv"
#define PACKAGE ""
#define LOCALEDIR ""
#define VERSION ""
#define TEXT_SMART_INDENT 1
#define TEXT_ALL_EFFECTIVE 2
#define TEXT_SOME_EFFECTIVE 4
#define TEXT_NUMERIC_IDS 8
#define WALK_TREE_RECURSIVE 1
#define WALK_TREE_LOGICAL 2
#define WALK_TREE_DEREFERENCE 4
#define WALK_TREE_PHYSICAL 8
#define WALK_TREE_DEREFERENCE_TOPLEVEL 16

struct option long_options[] = {0};

char *basename(char *path);
char *next_line(FILE *fp);
int walk_tree(const char *path, int flags, int depth, void (*fn)(const char *, void *), void *arg);
void do_print(const char *path, void *arg);
void help(void);