#include <stdio.h>
#include <stdarg.h>
#include <time.h>

typedef unsigned long long u64;
typedef unsigned int u32;

#define LLD "%lld"
#define LLU "%llu"

typedef enum {
    GF_LOG_RTI
} GF_LOG_Tool;

typedef enum {
    GF_LOG_Level_Info
} GF_LOG_Level;

extern FILE *rti_logs;
extern u64 log_time_start;
extern u64 last_log_time;
extern int log_utc_time;

u64 gf_sys_clock_high_res(void);
u64 gf_net_get_utc(void);
void UpdateRTInfo(const char *msg);