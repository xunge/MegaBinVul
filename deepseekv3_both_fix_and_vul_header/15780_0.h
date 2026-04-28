#include <sys/types.h>
#include <errno.h>

extern const char *g_settings_dump_location;
extern uid_t client_uid;

int dir_is_in_dump_location(const char *dump_dir_name);
int dump_dir_accessible_by_uid(const char *dump_dir_name, uid_t uid);
void error_msg(const char *fmt, ...);
void delete_dump_dir(const char *dump_dir_name);