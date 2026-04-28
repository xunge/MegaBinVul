#include <assert.h>
#include <string.h>
#include <strings.h>

#define CLIENT_ID_LEN 32
#define GLOBAL extern

typedef unsigned int UINT32;

typedef struct CLIENT {
    UINT32 hash;
    char id[CLIENT_ID_LEN];
    struct CLIENT *next;
} CLIENT;

GLOBAL CLIENT *My_Clients;

UINT32 Hash(const char *str);
size_t strlcpy(char *dst, const char *src, size_t siz);