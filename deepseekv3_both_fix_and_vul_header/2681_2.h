#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <iconv.h>

using namespace std;

#define DEBUG 1
#define ERROR 2
#define READ_BUFFER_SIZE 1024
#define HAVE_ICONV
#define LIBOFX_DEFAULT_INPUT_ENCODING "UTF-8"
#define LIBOFX_DEFAULT_OUTPUT_ENCODING "UTF-8"
#define OFX 1
#define OFC 2
#define OPENSPDCL_FILENAME "opensp.dcl"
#define OFX160DTD_FILENAME "ofx160.dtd"
#define OFCDTD_FILENAME "ofc.dtd"

typedef void* LibofxContextPtr;

struct LibofxContext {
    int currentFileType() { return 0; }
};

void message_out(int level, string msg);
string find_dtd(LibofxContextPtr ctx, const char* filename);
string sanitize_proprietary_tags(string buffer);
void ofx_proc_sgml(LibofxContext* ctx, int num_files, char* filenames[]);
void ofc_proc_sgml(LibofxContext* ctx, int num_files, char* filenames[]);

int mkTempFileName(const char* template_str, char* buffer, size_t size);