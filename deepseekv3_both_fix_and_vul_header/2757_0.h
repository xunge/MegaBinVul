#include <stddef.h>

#define BUG_ON(condition) do { if (condition) { /* handle bug */ } } while (0)
#define SYSLOG_PRI_MAX_LENGTH 32
#define LOG_BUF(index) (log_buf[index])

extern char log_buf[];
extern int default_message_loglevel;

unsigned int log_prefix(const char *buf, int *level, char *special);
void _call_console_drivers(unsigned start, unsigned end, int msg_level);