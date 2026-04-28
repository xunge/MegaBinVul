#include <stdbool.h>

#define BITS_PER_EVTCHN_WORD(d) (sizeof(unsigned long) * 8)

struct domain;
struct shared_info;

#define ASSERT(cond) ((void)0)
#define test_bit(nr, addr) (0)
#define shared_info(d, field) (0)

typedef bool bool_t;
typedef unsigned int evtchn_port_t;