#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define STATIC_FILE_FOLDER ""
#define MAX_PATH_SIZE 256
#define MAX_BODY_SIZE 1024

typedef struct {
    char *URI;
} HTTPReqHeader;

typedef struct {
    char _buf[MAX_BODY_SIZE];
    size_t _index;
} HTTPResMessage;

typedef struct {
    HTTPReqHeader Header;
} HTTPReqMessage;