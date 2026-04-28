#include <string>
#include <cstdlib>
#include <cstdio>
#include <sys/stat.h>
#include <string>

#ifdef WINDOWS
#include <windows.h>
#endif

using std::string;

#define NAME_BUFFER_SIZE 4096
#define DELIM_STR "/"
#define FILES_PROCESSED ""
#define BLANK_LINE ""
#define PRINT(fmt, ...) printf(__VA_ARGS__)

extern size_t aread(void*, size_t);
extern unsigned int fread32();
extern void try_aread(char*, size_t);
extern bool check_if_path_has_dir_traversal(const char*);
extern bool exists(const string&);
extern void decompress_file(const string&);
extern string remove_leading_curdir(const string&);
extern void abort(const char*, ...);
extern bool force_flag;
extern char tmp[NAME_BUFFER_SIZE];