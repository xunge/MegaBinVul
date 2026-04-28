#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

typedef char gchar;
#define g_strdup strdup
#define g_free free
#define g_file_test(filename, test) (access(filename, F_OK) == 0)
#define g_path_is_absolute(filename) (filename[0] == '/')
#define g_filename_from_uri(uri, hostname, error) (strdup(uri))
#define g_path_get_dirname(filename) (strdup(".")) 
#define g_get_current_dir() (getcwd(NULL, 0))
#define g_build_filename(...) (strdup("dummy_path"))