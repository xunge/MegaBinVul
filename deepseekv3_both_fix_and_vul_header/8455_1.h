#include <string.h>

struct archive_string {
    char *s;
    size_t length;
    size_t buffer_length;
};

struct file_info {
    struct file_info *parent;
    struct archive_string name;
};

size_t archive_strlen(const struct archive_string *as);
void archive_strcat(struct archive_string *as, const char *s);
void archive_string_concat(struct archive_string *as, const struct archive_string *s2);