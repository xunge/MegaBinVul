#include <stdlib.h>

extern char *statsdir;
extern struct filegen_t peerstats;
extern struct filegen_t loopstats;
extern struct filegen_t clockstats;
extern struct filegen_t rawstats;
extern struct filegen_t sysstats;
extern struct filegen_t protostats;
extern struct filegen_t cryptostats;
extern struct filegen_t timingstats;
extern void (*step_callback)(void);
extern void ntp_set_tod(void (*)(void));
extern void ntpd_time_stepped(void);
extern void uninit_util(void);
extern void filegen_register(char *, const char *, struct filegen_t *);

struct filegen_t;