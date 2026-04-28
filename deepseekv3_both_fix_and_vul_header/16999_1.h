#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SQLITE_DONE 101
#define SQLITE_OK 0

extern int db_update(char* name, char* data);