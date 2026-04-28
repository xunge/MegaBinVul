#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <string>
#include <cstdio>

extern void lwp_read(FILE *fin, std::string& str);