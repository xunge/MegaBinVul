#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int cbyte2;
extern int dsize;
extern int adds;
extern unsigned char* data2;
extern bool error;
extern uint64_t buf;
extern int cbit2;

enum ExitCode { MALLOCED_NULL };

void dev_assert(int condition);
bool bound_reached();
unsigned char* aligned_alloc(int size);
void aligned_dealloc(unsigned char* ptr);
void* custom_malloc(int size);
void custom_free(void* ptr);
void custom_exit(enum ExitCode code);
void flush_no_pad();

#define MBITS64(val, nbits, shift) ((((uint64_t)(val) >> (shift)) & ((1ULL << (nbits)) - 1)))
#define RBITS64(val, nbits) ((uint64_t)(val) & ((1ULL << (nbits)) - 1))