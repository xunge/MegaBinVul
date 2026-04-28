#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <string>

#define PAC_MAX_SIZE 1048576
#define PAC_HTTP_BLOCK_SIZE 4096
#define PAC_MIME_TYPE "application/x-ns-proxy-autoconfig"

struct url {
    std::string m_scheme;
    std::string m_path;
    std::string m_query;
    std::string m_host;
    struct sockaddr** m_ips;
    
    bool get_ips(bool);
    std::string recvline(int);
    char* get_pac();
};

#ifdef _WIN32
#define closesocket(s) close(s)
#else
#define closesocket(s) close(s)
#endif

using std::string;