#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef struct cJSON cJSON;

extern int Nread(int fd, char *buf, int nbytes, void *tcp);
extern void *Ptcp;
extern cJSON *cJSON_Parse(const char *value);