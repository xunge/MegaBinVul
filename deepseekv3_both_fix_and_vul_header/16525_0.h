#include <stdint.h>
#include <string.h>

#define NS_MAXLABEL 256
#define NS_RRFIXEDSZ 10

#define ns_c_in 1
#define ns_t_a 1
#define ns_t_aaaa 28
#define ns_t_cname 5
#define ns_t_soa 6

extern void debug(const char *fmt, ...);
extern int convert_label(char *start, char *end, char *ptr, char *name, int name_len, int *pos, int *comp_pos);