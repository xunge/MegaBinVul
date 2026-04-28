#include <stdlib.h>
#include <string.h>

struct archive_info {
    struct {
        char ar_name[16];
        char ar_fmag[2];
    } arhdr;
    char *longnames;
    unsigned long longnames_size;
    int is_thin_archive;
    unsigned long nested_member_origin;
    char *file_name;
};

extern void error(const char *fmt, ...);
extern char *adjust_relative_path(const char *file_name, const char *longnames, unsigned long len);
extern int setup_nested_archive(struct archive_info *nested_arch, const char *member_file_name);
extern char *get_archive_member_name_at(struct archive_info *nested_arch, unsigned long origin, void *unused);
extern void *xmalloc(size_t size);