#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

// 定义兼容不同平台的sockaddr_storage结构
#if defined(__linux__)
#define ss_len __ss_padding[0]
#elif defined(__APPLE__) || defined(__FreeBSD__)
#define ss_len ss_len
#else
#define ss_len __ss_align
#endif