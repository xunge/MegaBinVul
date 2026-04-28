#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <cassert>

typedef unsigned char upx_byte;

struct InputFile {
    void seek(unsigned offset, int whence);
    void readx(upx_byte* buf, unsigned size);
    unsigned tell();
};

struct OutputFile {
    void write(const void* buf, unsigned size);
    void write(const upx_byte* buf, unsigned size);
};

struct MemBuffer {
    void alloc(unsigned size);
    void allocForCompression(unsigned size);
    upx_byte* getData();
    upx_byte* operator+(unsigned offset);
    MemBuffer() = default;
    MemBuffer(unsigned size) { alloc(size); }
    operator upx_byte*() { return getData(); }
};

struct Packer {
    static void handleStub(InputFile* fi, OutputFile* fo, unsigned offset);
};

struct Filter {
    unsigned buf_len;
    Filter(unsigned level);
};

struct upx_compress_config_t {
    struct {
        unsigned max_num_probs;
    } conf_lzma;
    void reset();
};

template<typename T>
struct SPAN_S_VAR {
    T* ptr;
    SPAN_S_VAR(T* p) : ptr(p) {}
    operator T*() { return ptr; }
    T* operator+(unsigned offset) { return ptr + offset; }
};

struct ih_t {
    unsigned imagesize;
    unsigned relocsize;
    unsigned entry;
};

struct oh_t {
    unsigned imagesize;
    unsigned entry;
    unsigned relocsize;
};

struct ph_t {
    unsigned u_len;
    unsigned c_len;
    unsigned overlap_overhead;
    unsigned level;
};

struct Linker {
    void defineSymbol(const char* name, unsigned value);
};

struct PackTmt {
    unsigned big_relocs;
    unsigned file_size;
    unsigned adam_offset;
    ih_t ih;
    oh_t oh;
    ph_t ph;
    InputFile* fi;
    MemBuffer ibuf;
    MemBuffer obuf;
    Linker* linker;

    void pack(OutputFile* fo);
    void throwAlreadyPacked();
    void throwCantPack(const char* msg);
    void checkOverlay(unsigned overlay);
    unsigned optimizeReloc32(upx_byte* src, unsigned count, upx_byte* dst, MemBuffer& buf, unsigned size, bool flag, unsigned* big_relocs);
    unsigned getLoaderSize();
    unsigned getLoaderSection(const char* name);
    int getLoaderSectionStart(const char* name);
    void defineDecompressorSymbols();
    void defineFilterSymbols(Filter* ft);
    void relocateLoader();
    upx_byte* getLoader();
    void patchPackHeader(MemBuffer& loader, int e_len);
    void verifyOverlappingDecompression();
    void copyOverlay(OutputFile* fo, unsigned overlay, MemBuffer& obuf);
    bool checkFinalCompressionRatio(OutputFile* fo);
    void throwNotCompressible();
    void compressWithFilters(Filter* ft, unsigned size, upx_compress_config_t* cconf);
};

#define UPX_MIN(a, b) ((a) < (b) ? (a) : (b))
#define EXTRA_INFO 8
#define SEEK_SET 0

unsigned find_le32(const upx_byte* buf, unsigned size, unsigned value);
unsigned get_le32(const upx_byte* buf);
unsigned get_le32(const char* buf);
void set_le32(void* buf, unsigned value);

// Helper macro for SPAN_S_VAR
#define SPAN_S_VAR(type, name, buffer) type* name = buffer.getData()