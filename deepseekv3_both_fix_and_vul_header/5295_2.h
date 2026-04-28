#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>

typedef enum {
    GF_LOG_Level_DEFAULT
} GF_LOG_Level;

typedef enum {
    GF_LOG_RTI
} GF_LOG_Tool;

extern FILE *rti_logs;
extern uint64_t log_time_start;
extern uint64_t last_log_time;
extern int log_utc_time;

typedef uint64_t u64;
typedef uint32_t u32;
#define LLD PRId64
#define LLU PRIu64

void UpdateRTInfo(const char *msg);
uint64_t gf_sys_clock_high_res();
uint64_t gf_net_get_utc();