#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>

#define RFC3397 0x01
#define RFC3361 0x02
#define RFC3442 0x04
#define RFC5969 0x08
#define STRING 0x10
#define UINT8 0x20
#define UINT16 0x40
#define SINT16 0x80
#define UINT32 0x100
#define SINT32 0x200
#define IPV4 0x400

extern ssize_t decode_rfc3397(char *, ssize_t, int, const uint8_t *);
extern char *decode_rfc3361(int, const uint8_t *);
extern ssize_t decode_rfc3442(char *, ssize_t, int, const uint8_t *);
extern ssize_t decode_rfc5969(char *, ssize_t, int, const uint8_t *);
extern ssize_t print_string(char *, ssize_t, ssize_t, const uint8_t *);
extern void *xmalloc(size_t);