#include <stdlib.h>
#include <sys/types.h>

typedef struct Channel Channel;
typedef unsigned short u_short;

extern char *packet_get_string(int *);
extern int packet_get_int(void);
extern void packet_check_eom(void);
extern void debug(const char *, ...);
extern void logit(const char *, ...);

struct {
    int allow_streamlocal_forwarding;
    int disable_forwarding;
} options;

extern int no_port_forwarding_flag;
extern int use_privsep;

#define FORWARD_LOCAL 1