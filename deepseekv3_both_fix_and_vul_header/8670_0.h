#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

typedef int (*tar_extractor_t)(const char *, char);

extern int interactive_option;
extern int verbose_option;
extern int delay_directory_restore_option;
extern int backup_option;
extern int chdir_current;
extern int absolute_names_option;
extern struct stat current_stat_info;
extern union block *current_header;
extern void (*fatal_exit_hook)(void);

#define GNUTYPE_SPARSE 'S'

void extract_finish(void);
void set_next_block_after(union block *);
void skip_member(void);
int confirm(const char *, const char *);
void print_header(struct stat *, union block *, int);
void apply_nonancestor_delayed_set_stat(const char *, int);
void chdir_do(int);
int maybe_backup_file(const char *, int);
void ERROR(int, int, const char *, const char *);
char *quotearg_colon(const char *);
int sparse_member_p(struct stat *);
int prepare_to_extract(const char *, char, tar_extractor_t *);
void undo_last_backup(void);
const char *_(const char *);
bool contains_dot_dot(const char *);

union block {
    struct {
        char typeflag;
    } header;
};

struct stat {
    char file_name[1];
    char orig_file_name[1];
};

#define ERROR(args) ERROR args
#define _(x) x