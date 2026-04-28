#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct instance_data;

static int protect_mount(int dfd, const char *path, struct instance_data *idata);