#include <stdint.h>
#include <cassert>
#include <cstddef>
#include <vector>

enum BlockType {};
enum ColorChannel { NumBlockTypes };
enum CodingReturnValue { CODING_PARTIAL, CODING_DONE };

namespace Sirikata {
template<typename T, std::size_t N>
struct Array1d {
    T& operator[](std::size_t);
};
}

template<bool b>
struct BlockBasedImagePerChannel {
    struct Component {
        int block_width();
    };
    Component*& operator[](int);
};

struct UncompressedComponents {
    int get_num_components();
    uint32_t component_size_in_blocks(int);
    BlockBasedImagePerChannel<false>::Component& full_component_write(BlockType);
    Sirikata::Array1d<uint32_t, static_cast<std::size_t>(ColorChannel::NumBlockTypes)> get_max_coded_heights();
    int get_mcu_count_vertical();
    void worker_update_cmp_progress(BlockType, int);
};

struct RowSpec {
    bool done;
    bool skip;
    int luma_y;
    int component;
    int curr_y;
};

namespace LeptonCodec {
struct ThreadState {
    std::vector<int> luma_splits_;
    int decode_index_;
    CodingReturnValue vp8_decode_thread(unsigned int, UncompressedComponents* const);
};
}

RowSpec row_spec_from_index(int, BlockBasedImagePerChannel<false>&, int, Sirikata::Array1d<uint32_t, static_cast<std::size_t>(ColorChannel::NumBlockTypes)>);
void decode_rowf(BlockBasedImagePerChannel<false>&, Sirikata::Array1d<uint32_t, static_cast<uint32_t>(ColorChannel::NumBlockTypes)>, int, int);

#define NUM_THREADS 4
#define dev_assert(x) assert(x)
#define always_assert(x) assert(x)