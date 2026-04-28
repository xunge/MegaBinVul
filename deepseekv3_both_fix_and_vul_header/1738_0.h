#include <stdio.h>
#include <string.h>

#define TRACE(x)
#define CHECKCLEARTOWRITE()
#define DROPBEAR_CLI_ASKPASS_HELPER 0
#define SSH_MSG_USERAUTH_REQUEST 0
#define SSH_SERVICE_CONNECTION "ssh-connection"
#define SSH_SERVICE_CONNECTION_LEN strlen(SSH_SERVICE_CONNECTION)
#define AUTH_METHOD_PASSWORD "password"
#define AUTH_METHOD_PASSWORD_LEN strlen(AUTH_METHOD_PASSWORD)

struct {
    char* username;
    char* remotehost;
} cli_opts;

struct {
    int is_trivial_auth;
} cli_ses;

struct {
    void* writepayload;
} ses;

void dropbear_exit(const char* msg);
char* gui_getpass(const char* prompt);
int want_askpass(void);
char* getpass_or_cancel(const char* prompt);
void buf_putbyte(void* buf, unsigned char val);
void buf_putstring(void* buf, const char* str, unsigned int len);
void encrypt_packet(void);
void m_burn(void* data, unsigned int len);