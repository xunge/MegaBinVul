#include <sys/time.h>

struct sas_task {
    struct slow_task *slow_task;
};

struct slow_task {
    struct itimerval timer;
    int completion;
};