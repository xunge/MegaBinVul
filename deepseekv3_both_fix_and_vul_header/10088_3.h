#include <stddef.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <stdint.h>

#define _IO_FLAGS2_USER_WBUF 0x0008
#define __wmemcpy wmemcpy

typedef struct _IO_FILE _IO_FILE;
typedef struct _IO_wide_data _IO_wide_data;
typedef struct _IO_strfile _IO_strfile;
typedef __off64_t _IO_off64_t;
typedef ssize_t _IO_ssize_t;
typedef size_t _IO_size_t;

struct _IO_wide_data {
    wchar_t *_IO_read_ptr;
    wchar_t *_IO_read_end;
    wchar_t *_IO_read_base;
    wchar_t *_IO_write_base;
    wchar_t *_IO_write_ptr;
    wchar_t *_IO_write_end;
    wchar_t *_IO_buf_base;
    wchar_t *_IO_buf_end;
};

struct _IO_strfile {
    struct {
        void *(*_allocate_buffer)(size_t);
        void (*_free_buffer)(void*);
    } _s;
};

static _IO_ssize_t _IO_blen(_IO_FILE *fp) { return 0; }
static _IO_size_t _IO_wblen(_IO_FILE *fp) { return 0; }
static void _IO_wsetb(_IO_FILE *fp, wchar_t *b, wchar_t *eb, int a) {}