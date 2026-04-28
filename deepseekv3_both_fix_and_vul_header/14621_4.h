#include <stdlib.h>
#include <assert.h>

#define GF_EXPORT

typedef struct GF_BifsDecoder GF_BifsDecoder;
typedef struct BIFSStreamInfo BIFSStreamInfo;
typedef struct GF_Node GF_Node;

struct CommandBufferItem {
    struct GF_Node* node;
};

struct GF_BifsDecoder {
    void* QPs;
    void* streamInfo;
    void* command_buffers;
};

void gf_list_del(void* list);
int gf_list_count(void* list);
void* gf_list_get(void* list, int index);
void gf_list_rem(void* list, int index);
void gf_free(void* ptr);
void gf_node_unregister(struct GF_Node* node, void* ptr);
void bifs_info_del(struct BIFSStreamInfo* p);

typedef struct CommandBufferItem CommandBufferItem;