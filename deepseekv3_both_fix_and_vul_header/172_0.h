#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <syslog.h>

struct header {
    char *p;
    int l;
};

struct device {
    struct device *next;
    time_t t;
    struct header headers[3];
    char data[];
};

static struct device *devlist;

enum {
    HEADER_NT,
    HEADER_USN,
    HEADER_LOCATION
};

enum {
    NOTIF_NEW
};

void sendNotifications(int type, struct device *dev, void *arg);