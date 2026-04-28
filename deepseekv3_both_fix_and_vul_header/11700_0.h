#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct smtp {
    char *email_to;
    char *subject;
    char *body;
} smtp_t;

typedef struct global_data {
    char *email_from;
} global_data_t;

extern global_data_t *global_data;

void free_smtp_all(smtp_t *smtp);