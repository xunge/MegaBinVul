#include <cstdint>
#include <cstddef>

struct OutputDetails {
    uint8_t* consensus;
    uint16_t* coverage;
    uint8_t* multiple_sequence_alignments;
};

enum OutputType {
    consensus = 1,
    msa = 2
};

class BatchBlock {
public:
    void get_output_details(OutputDetails** output_details_h_p, OutputDetails** output_details_d_p);
    
    uint8_t* block_data_h_;
    uint8_t* block_data_d_;
    size_t offset_h_;
    size_t offset_d_;
    size_t output_size_;
    int output_mask_;
    size_t max_sequences_per_poa_;
};

namespace cudautils {
    template<typename T, size_t alignment>
    constexpr T align(T value) {
        return (value + alignment - 1) & ~(alignment - 1);
    }
}