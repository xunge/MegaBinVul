#include <cstdint>
#include <cstddef>

#define CUDAPOA_MAX_NODE_ALIGNMENTS 16
#define CUDAPOA_MAX_NODE_EDGES 16

struct GraphDetails {
    uint8_t* nodes;
    uint16_t* node_alignments;
    uint16_t* node_alignment_count;
    uint16_t* incoming_edges;
    uint16_t* incoming_edge_count;
    uint16_t* outgoing_edges;
    uint16_t* outgoing_edge_count;
    uint16_t* incoming_edge_weights;
    uint16_t* outgoing_edge_weights;
    uint16_t* sorted_poa;
    uint16_t* sorted_poa_node_map;
    uint16_t* sorted_poa_local_edge_count;
    int32_t* consensus_scores;
    int16_t* consensus_predecessors;
    uint8_t* node_marks;
    bool* check_aligned_nodes;
    uint16_t* nodes_to_visit;
    uint16_t* node_coverage_counts;
    uint16_t* outgoing_edges_coverage;
    uint16_t* outgoing_edges_coverage_count;
    int16_t* node_id_to_msa_pos;
};

enum OutputType {
    consensus = 1,
    msa = 2
};

class BatchBlock {
public:
    uint8_t* block_data_h_;
    uint8_t* block_data_d_;
    size_t offset_h_;
    size_t offset_d_;
    size_t max_nodes_per_window_;
    size_t max_poas_;
    size_t max_sequences_per_poa_;
    int output_mask_;
    
    void get_graph_details(GraphDetails** graph_details_d_p);
};

namespace cudautils {
    template<typename T, size_t alignment>
    constexpr size_t align(size_t size) {
        return (size + alignment - 1) & ~(alignment - 1);
    }
};