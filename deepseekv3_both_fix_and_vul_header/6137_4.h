#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOUNTS "/proc/mounts"
#define DFHASHSIZE 256

struct nlist {
    struct nlist *next;
};

typedef struct {
    double total;
    double free;
} DiskInfo;

int remote_mount(char *device, char *type);

/* First version declarations */
float device_space_v1(struct nlist **DFhashvector, char *mount, char *device, double *dtotal, double *dfree);
void DFcleanup_v1(struct nlist **DFhashvector);

/* Second version declarations */
float device_space_v2(char *mount, char *device, double *dtotal, double *dfree);
void DFcleanup_v2(void);