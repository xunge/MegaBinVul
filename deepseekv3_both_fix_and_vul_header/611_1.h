#include <stdio.h>

typedef struct xref_entry {
    int byte_offset;
    int generation;
    char use;
    struct xref_entry *next;
} xref_entry;

class pdf_print {
public:
    void file_xref();
};

class OutputStream {
public:
    void PutString(const char*);
};

extern OutputStream* pr_out;
extern xref_entry* xref_root;
extern int xref_count;
extern int Error;
extern void dbg0(int, const char*);