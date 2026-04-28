#include <assert.h>
#include <syslog.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define MAX_MAILBOX_PATH 1024
#define EXPORTED

struct message_guid;

const char *config_archivepartitiondir(const char *part);
const char *config_partitiondir(const char *part);
char *message_guid_encode(const struct message_guid *guid);
int cyrus_mkdir(const char *path, int mode);