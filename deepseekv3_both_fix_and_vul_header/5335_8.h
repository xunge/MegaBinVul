#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <atomic>
#include <functional>
#include <memory>
#include <unistd.h>
#include <cerrno>

namespace Sirikata {
    template<typename T> class JpegAllocator {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        
        JpegAllocator();
        template<typename U>
        JpegAllocator(const JpegAllocator<U>&);
        
        pointer allocate(size_type n);
        void deallocate(pointer p, size_type n);
        
        void setup_memory_subsystem(size_t, int, 
                                   void* (*)(), 
                                   void* (*)(size_t),
                                   void* (*)(),
                                   void* (*)(void*, size_t),
                                   size_t (*)(void*));
    };
    
    struct JpegError {
        operator bool() const { return false; }
    };
    
    class BrotliCodec {
    public:
        static std::pair<std::vector<uint8_t, JpegAllocator<uint8_t>>, JpegError> 
        Decompress(const uint8_t*, size_t, const JpegAllocator<uint8_t>&, size_t);
    };
    
    class ZlibDecoderDecompressionReader {
    public:
        static std::pair<std::vector<uint8_t, JpegAllocator<uint8_t>>, JpegError> 
        Decompress(const uint8_t*, size_t, const JpegAllocator<uint8_t>&, size_t);
    };
    
    enum Billing { HEADER, DELIMITERS };
    enum ExitCode { SHORT_READ, STREAM_INCONSISTENT };
    void write_byte_bill(Billing, bool, size_t);
    void custom_exit(ExitCode);
}

namespace IOUtil {
    class MemReadWriter {
    public:
        MemReadWriter();
        explicit MemReadWriter(const Sirikata::JpegAllocator<uint8_t>&);
        void Read(unsigned char*, size_t);
        void SwapIn(const std::vector<uint8_t, Sirikata::JpegAllocator<uint8_t>>&, size_t);
    };
    int ReadFull(void*, unsigned char*, size_t);
}

struct ThreadHandoff {
    static std::vector<ThreadHandoff> deserialize(unsigned char*, size_t);
    static size_t get_remaining_data_size_from_two_bytes(unsigned char*);
};

#define always_assert(expr) ((expr) ? (void)0 : (custom_exit(Sirikata::ExitCode::STREAM_INCONSISTENT)))
#define MEM_ERRMSG "Memory allocation error\n"
#define NUM_THREADS 4
#define UJG 1

extern std::atomic<int> errorlevel;
extern void* str_in;
struct StreamOut {
    void call_size_callback(size_t);
};
extern StreamOut* str_out;
extern size_t max_file_size;
extern IOUtil::MemReadWriter* header_reader;
extern int ujgversion;
extern size_t zlib_hdrs;
extern size_t grbs;
extern unsigned char* grbgdata;
extern unsigned char EOI[2];
extern size_t hdrs;
extern unsigned char* hdrdata;
extern int filetype;
extern bool g_allow_progressive;
extern int padbit;
extern bool rst_cnt_set;
extern std::vector<uint32_t> rst_cnt;
extern size_t scnc;
extern std::vector<uint8_t> rst_err;
extern size_t prefix_grbs;
extern unsigned char* prefix_grbgdata;
extern bool embedded_jpeg;
extern uint32_t max_cmp;
extern uint32_t max_bpos;
extern uint32_t max_sah;
extern uint32_t max_dpos[4];
extern bool early_eof_encountered;
struct CollData {
    void signal_worker_should_begin();
    void start_decoder(void*);
    void set_truncation_bounds(uint32_t, uint32_t, uint32_t[4], uint32_t);
};
extern CollData colldata;
struct Decoder {
    void initialize(void*, const std::vector<ThreadHandoff>&);
};
extern Decoder* g_decoder;

inline uint32_t LEtoUint32(const unsigned char* buf) {
    return buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
}

inline unsigned char* aligned_alloc(size_t size) {
    return static_cast<unsigned char*>(malloc(size));
}

bool setup_imginfo_jpg(bool);

// Memory management functions
extern "C" {
    void* mem_init_nop();
    void* MemMgrAllocatorMalloc(size_t);
    void* mem_nop();
    void* mem_realloc_nop(void*, size_t);
    size_t MemMgrAllocatorMsize(void*);
}