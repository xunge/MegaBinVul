#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define Max_num_extensions 256

typedef struct {
    int map_id;
    uint32_t size;
    uint16_t extension_size;
    uint16_t *ex_id;
} extension_map_t;

typedef struct {
    int size;
} extension_descriptor_t;

extern extension_descriptor_t extension_descriptor[Max_num_extensions];