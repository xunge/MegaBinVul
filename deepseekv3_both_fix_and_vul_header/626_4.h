#include <cstdint>
#include <string>
#include <stdexcept>
#include <tuple>

#define CUDAPOA_BANDED_MAX_MATRIX_SEQUENCE_DIMENSION 0
#define CUDAPOA_MAX_MATRIX_SEQUENCE_DIMENSION 0
#define CUDAPOA_MAX_MATRIX_GRAPH_DIMENSION_BANDED 0
#define CUDAPOA_MAX_MATRIX_GRAPH_DIMENSION 0
#define CUDAPOA_MAX_NODES_PER_WINDOW_BANDED 0
#define CUDAPOA_MAX_NODES_PER_WINDOW 0
#define CUDAPOA_MAX_CONSENSUS_SIZE 0
#define CUDAPOA_MAX_SEQUENCE_SIZE 0

#define CGA_CU_CHECK_ERR(call) call

enum cudaError {
    cudaSuccess = 0
};

inline int cudaSetDevice(int device) { return cudaSuccess; }
inline int cudaHostAlloc(void** ptr, size_t size, unsigned int flags) { return cudaSuccess; }
inline int cudaMalloc(void** devPtr, size_t size) { return cudaSuccess; }
constexpr unsigned int cudaHostAllocDefault = 0;

class BatchBlock {
public:
    BatchBlock(int32_t device_id, size_t avail_mem, int32_t max_sequences_per_poa, int8_t output_mask, bool banded_alignment);

private:
    int32_t max_sequences_per_poa_;
    bool banded_alignment_;
    int32_t device_id_;
    int8_t output_mask_;
    size_t matrix_sequence_dimension_;
    size_t max_graph_dimension_;
    size_t max_nodes_per_window_;
    size_t max_poas_;
    size_t output_size_;
    size_t input_size_;
    size_t total_h_;
    size_t total_d_;
    void* block_data_h_;
    void* block_data_d_;

    int32_t throw_on_negative(int32_t value, const std::string& message) {
        if (value < 0) {
            throw std::runtime_error(message);
        }
        return value;
    }

    std::tuple<size_t, size_t, size_t, size_t> calculate_space_per_poa() {
        return std::make_tuple(0, 0, 0, 0);
    }
};