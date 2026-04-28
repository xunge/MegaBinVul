#include <cstdint>
#include <cstddef>

struct WindowDetails {
    // Add necessary members here
};

struct InputDetails {
    uint8_t* sequences;
    int8_t* base_weights;
    uint16_t* sequence_lengths;
    WindowDetails* window_details;
    uint16_t* sequence_begin_nodes_ids;
};

enum OutputType {
    msa = 0x1
};

namespace cudautils {
    template<typename T, size_t Alignment>
    constexpr T align(T size) {
        return (size + Alignment - 1) & ~(Alignment - 1);
    }
}

class BatchBlock {
public:
    void get_input_details(InputDetails** input_details_h_p, InputDetails** input_details_d_p);
    
    uint8_t* block_data_h_;
    uint8_t* block_data_d_;
    size_t offset_h_;
    size_t offset_d_;
    size_t input_size_;
    size_t max_poas_;
    size_t max_sequences_per_poa_;
    int output_mask_;
};