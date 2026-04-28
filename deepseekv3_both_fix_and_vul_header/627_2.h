#include <cstdint>
#include <cstdlib>

struct AlignmentDetails {
    int16_t* alignment_graph;
    int16_t* alignment_read;
    size_t scorebuf_alloc_size;
    int16_t* scores;
};

class BatchBlock {
public:
    void get_alignment_details(AlignmentDetails** alignment_details_d_p);
    char* block_data_h_;
    char* block_data_d_;
    size_t offset_h_;
    size_t offset_d_;
    size_t max_graph_dimension_;
    size_t max_poas_;
    size_t total_d_;
};

namespace cudautils {
    template<typename T, size_t alignment>
    constexpr T align(T size) {
        return (size + alignment - 1) & ~(alignment - 1);
    }
}