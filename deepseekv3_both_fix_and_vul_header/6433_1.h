#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned long bfd_size_type;

typedef struct Frame_Chunk {
    short int *col_type;
    int *col_offset;
    char *augmentation;
    int ptr_size;
    int segment_size;
    int code_factor;
    int data_factor;
    int ra;
    int fde_encoding;
} Frame_Chunk;

extern void *xmalloc(size_t size);
extern void warn(const char *format, ...);
extern const char *dwarf_vmatoa(const char *fmt, bfd_size_type val);
extern int eh_addr_size;
extern int size_of_encoded_value(unsigned char);

#define GET(var, size) \
    do { \
        if (start + size > end) { \
            warn("Unexpected end of data\n"); \
            return end; \
        } \
        memcpy(&(var), start, size); \
        start += size; \
    } while (0)

#define READ_ULEB(var) \
    do { \
        var = 0; \
        int shift = 0; \
        unsigned char byte; \
        do { \
            if (start >= end) { \
                warn("Unexpected end of data\n"); \
                return end; \
            } \
            byte = *start++; \
            var |= (byte & 0x7f) << shift; \
            shift += 7; \
        } while (byte & 0x80); \
    } while (0)

#define READ_SLEB(var) \
    do { \
        var = 0; \
        int shift = 0; \
        unsigned char byte; \
        do { \
            if (start >= end) { \
                warn("Unexpected end of data\n"); \
                return end; \
            } \
            byte = *start++; \
            var |= (byte & 0x7f) << shift; \
            shift += 7; \
        } while (byte & 0x80); \
        if (byte & 0x40 && shift < (int)sizeof(var) * 8) \
            var |= -(1 << shift); \
    } while (0)