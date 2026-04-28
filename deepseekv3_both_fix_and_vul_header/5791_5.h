#include <stdbool.h>
#include <stddef.h>

bool waiting_for_callback_;
bool aborted_;
void* aborted_self_ref_;
void* self_ref_;

#define override
#define this ((void*)0)