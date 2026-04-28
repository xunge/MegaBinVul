#include <string.h>
#include <stdint.h>
#include <stdio.h>

class PackTmt {
public:
    int readFileHeader();
};

struct {
    unsigned imagesize;
    unsigned entry;
    unsigned relocsize;
} ih;

unsigned adam_offset;
unsigned file_size;
class File {
public:
    void seek(unsigned, int);
    void readx(void *, size_t);
};
File *fi;

int get_le16(const unsigned char *);
int get_le32(const unsigned char *);
void printWarn(const char *, const char *, ...);
const char *getName();
#define UPX_F_TMT_ADAM 0
#define SEEK_SET 0