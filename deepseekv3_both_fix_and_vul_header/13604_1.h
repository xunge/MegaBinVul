#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stddef.h>

struct dri_sw_displaytarget {
   int shmid;
};