#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <wchar.h>

extern wchar_t *path;
extern wchar_t *user;
extern int get_socket_count;
extern const char *SOCK_FILENAME;
extern char *wcs2str(const wchar_t *wstr);
extern std::string wcs2string(const wchar_t *wstr);
extern void debug(int level, const wchar_t *fmt, ...);
extern int make_fd_nonblocking(int fd);
extern void wperror(const wchar_t *s);
extern int getpeereid(int sockfd, uid_t *euid, gid_t *egid);