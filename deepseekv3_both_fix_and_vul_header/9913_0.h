#include <stdlib.h>

typedef struct _MonoDomain MonoDomain;

void mono_domain_foreach(void (*func)(MonoDomain*, void*), void* user_data);
void fire_process_exit_event(MonoDomain* domain, void* user_data);