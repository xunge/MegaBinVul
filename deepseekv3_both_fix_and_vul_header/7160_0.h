#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_NAME_LEN 1024

#define GSS_S_COMPLETE 0
#define GSS_S_BAD_NAME 1

#define ERR_NAMETOOLONG 1
#define EINVAL 22
#define ENOMEM 12

#define GSSERRS(a, b) ((a) << 16 | (b))
#define GSSERR() (retmaj << 16 | retmin)

static uint32_t retmaj;
static uint32_t retmin;

static void set_GSSERR(int err) {
    retmaj = 0;
    retmin = err;
}

static void set_GSSERRS(uint32_t maj, uint32_t min) {
    retmaj = maj;
    retmin = min;
}

static uint32_t string_split(uint32_t *minor_status, char sep, const char *str, size_t len, char **part1, char **part2);