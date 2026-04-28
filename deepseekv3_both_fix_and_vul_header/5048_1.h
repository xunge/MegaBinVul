#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <cstddef>

#define unlikely(x) (x)
#define errno_assert(x) assert(x)

namespace zmq {
    class v2_decoder_t {
    public:
        int size_ready(uint64_t msg_size_, unsigned char const* read_pos_);
    private:
        int _max_msg_size;
        bool _zero_copy;
        int _msg_flags;
        class message_t {
        public:
            int close();
            int init_size(std::size_t size);
            int init(unsigned char* data, std::size_t size, void (*deallocator)(void*, void*), void* hint, bool provided);
            int init();
            bool is_zcmsg();
            void* data();
            std::size_t size();
            void set_flags(int flags);
        } _in_progress;
        class shared_message_memory_allocator {
        public:
            unsigned char* data();
            std::size_t size();
            void* buffer();
            bool provide_content();
            void advance_content();
            void inc_ref();
            static void call_dec_ref(void*, void*);
        };
        shared_message_memory_allocator& get_allocator();
        void next_step(void* data, std::size_t size, int (v2_decoder_t::*callback)());
        int message_ready();
    };
}