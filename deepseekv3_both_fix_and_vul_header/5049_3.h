#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <cstddef>

#define unlikely(x) (x)
#define errno_assert(x) assert(x)

namespace zmq {
    class shared_message_memory_allocator {
    public:
        unsigned char* data();
        std::size_t size();
        void advance_content();
        void inc_ref();
        void* buffer();
        bool provide_content();
        static void call_dec_ref(void*, void*);
    };

    class zmq_msg_t {
    public:
        int close();
        int init_size(std::size_t);
        int init(unsigned char*, std::size_t, void (*)(void*, void*), void*, bool);
        bool is_zcmsg();
        void set_flags(int);
        unsigned char* data();
        std::size_t size();
        int init();
    };

    class v2_decoder_t {
    public:
        int _max_msg_size;
        zmq_msg_t _in_progress;
        bool _zero_copy;
        int _msg_flags;
        shared_message_memory_allocator& get_allocator();
        void next_step(void*, std::size_t, int (v2_decoder_t::*)());
        int message_ready();
        int size_ready(uint64_t, const unsigned char*);
    };
}