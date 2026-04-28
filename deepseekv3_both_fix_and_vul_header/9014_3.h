#include <stdio.h>
#include <stdlib.h>

#define FAILURE 0
#define SUCCESS 1
#define PHAR_MOD 1
#define TAR_FILE '0'

typedef struct _phar_archive_data {
    int is_data;
    int is_persistent;
    int refcount;
} phar_archive_data;

typedef struct _phar_entry_info {
    int is_modified;
    int fp_refcount;
    int is_deleted;
    int is_dir;
    int is_zip;
    int is_tar;
    int fp_type;
    char *link;
    char tar_type;
    phar_archive_data *phar;
} phar_entry_info;

typedef struct _phar_entry_data {
    size_t position;
    FILE *fp;
    phar_archive_data *phar;
    int for_write;
    phar_entry_info *internal_file;
    int is_zip;
    int is_tar;
    size_t zero;
} phar_entry_data;

extern int PHAR_G_readonly;
#define PHAR_G(v) (PHAR_G_##v)

extern void *emalloc(size_t size);
extern void efree(void *ptr);
extern int spprintf(char **str, size_t max_len, const char *format, ...);
extern int phar_get_archive(phar_archive_data **phar, char *fname, int fname_len, char *alias, int alias_len, char **error);
extern phar_entry_info *phar_get_entry_info_dir(phar_archive_data *phar, char *path, int path_len, char dir, char **error, int security);
extern phar_entry_info *phar_get_entry_info(phar_archive_data *phar, char *path, int path_len, char **error, int security);
extern int phar_copy_on_write(phar_archive_data **phar);
extern int phar_create_writeable_entry(phar_archive_data *phar, phar_entry_info *entry, char **error);
extern void phar_seek_efp(phar_entry_info *entry, off_t offset, int whence, int offset_emulation, int seek_quiet);
extern int phar_separate_entry_fp(phar_entry_info *entry, char **error);
extern int phar_open_entry_fp(phar_entry_info *entry, char **error, int follow_links);
extern FILE *phar_get_efp(phar_entry_info *entry, int follow_links);
extern phar_entry_info *phar_get_link_source(phar_entry_info *entry);
extern size_t phar_get_fp_offset(phar_entry_info *entry);