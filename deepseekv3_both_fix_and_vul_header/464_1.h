#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <strings.h>

#define MAX_PKT_SIZE 1500
#define SSDP_ST_ALL "ssdp:all"

struct ifsock;
extern struct ifsock *find_outbound(struct sockaddr *sa);
extern void logit(int level, const char *fmt, ...);
extern void send_message(struct ifsock *ifs, char *type, struct sockaddr *sa);
extern char *supported_types[];