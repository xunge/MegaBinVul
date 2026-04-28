#include <stdlib.h>
#include <string.h>

struct dump_dir {
    char *dd_dirname;
};

char *concat_path_file(const char *dir, const char *filename);
int exist_file_dir(const char *path);