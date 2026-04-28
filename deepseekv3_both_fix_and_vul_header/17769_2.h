#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <syslog.h>

#define GLOBAL
#define COMMAND_LEN 512
#define CONNECTED true

typedef struct CLIENT CLIENT;
typedef struct CHANNEL CHANNEL;
typedef struct REQUEST {
    char *argv[2];
} REQUEST;

size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);

CLIENT *Client_Search(char *nick);
bool Channel_Join(CLIENT *client, char *channel);
void Log(int level, const char *format, ...);
void IRC_KillClient(CLIENT *source, CLIENT *target, char *nick, char *reason);
CHANNEL *Channel_Search(char *channel);
void Channel_UserModeAdd(CHANNEL *channel, CLIENT *client, char mode);
void IRC_WriteStrChannelPrefix(CLIENT *source, CHANNEL *channel, CLIENT *target, bool silent, const char *format, ...);
char *Channel_UserModes(CHANNEL *channel, CLIENT *client);
char *Client_ID(CLIENT *client);
void IRC_WriteStrServersPrefix(CLIENT *source, CLIENT *server, const char *format, ...);
CLIENT *Client_ThisServer(void);