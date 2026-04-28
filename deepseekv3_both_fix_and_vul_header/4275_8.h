#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

typedef int32_t status_t;
typedef int32_t node_id;
typedef int32_t buffer_id;
typedef uint32_t OMX_U32;
typedef int32_t OMX_S32;
typedef int64_t OMX_TICKS;
typedef int32_t OMX_BOOL;

enum {
    OK = 0,
    NO_ERROR = 0,
    INVALID_OPERATION
};

enum {
    LIVES_LOCALLY,
    LIST_NODES,
    ALLOCATE_NODE,
    FREE_NODE,
    SEND_COMMAND,
    GET_PARAMETER,
    SET_PARAMETER,
    GET_CONFIG,
    SET_CONFIG,
    SET_INTERNAL_OPTION,
    GET_STATE,
    ENABLE_GRAPHIC_BUFFERS,
    GET_GRAPHIC_BUFFER_USAGE,
    USE_BUFFER,
    USE_GRAPHIC_BUFFER,
    UPDATE_GRAPHIC_BUFFER_IN_META,
    CREATE_INPUT_SURFACE,
    SIGNAL_END_OF_INPUT_STREAM,
    STORE_META_DATA_IN_BUFFERS,
    PREPARE_FOR_ADAPTIVE_PLAYBACK,
    CONFIGURE_VIDEO_TUNNEL_MODE,
    ALLOC_BUFFER,
    ALLOC_BUFFER_WITH_BACKUP,
    FREE_BUFFER,
    FILL_BUFFER,
    EMPTY_BUFFER,
    GET_EXTENSION_INDEX
};

typedef enum OMX_COMMANDTYPE {
    OMX_CommandStateSet,
    OMX_CommandFlush,
    OMX_CommandPortDisable,
    OMX_CommandPortEnable,
    OMX_CommandMarkBuffer
} OMX_COMMANDTYPE;

typedef enum OMX_STATETYPE {
    OMX_StateInvalid,
    OMX_StateLoaded,
    OMX_StateIdle,
    OMX_StateExecuting,
    OMX_StatePause,
    OMX_StateWaitForResources
} OMX_STATETYPE;

typedef enum OMX_INDEXTYPE {
    OMX_IndexComponentStartUnused = 0x01000000,
    OMX_IndexParamVideoStartUnused = 0x02000000,
    OMX_IndexConfigVideoStartUnused = 0x03000000
} OMX_INDEXTYPE;

typedef int32_t InternalOptionType;

class String8 {
public:
    String8();
    explicit String8(const char* str);
    const char* string() const;
    size_t size() const;
};

class GraphicBuffer {
public:
    GraphicBuffer();
    status_t readFromParcel(const class Parcel& parcel);
};

class Parcel {
public:
    int32_t readInt32() const;
    int64_t readInt64() const;
    const char* readCString() const;
    void read(void* data, size_t size) const;
    status_t read(GraphicBuffer& buffer) const;
    void writeInt32(int32_t value);
    void writeInt64(int64_t value);
    void writeString8(const String8& str);
    void write(const void* data, size_t size);
    void* readStrongBinder() const;
    void writeStrongBinder(void* binder);
    void writeNativeHandle(void* handle);
};

template<typename T>
class List {
public:
    class iterator {
    public:
        iterator();
        T& operator*() const;
        iterator& operator++();
        bool operator!=(const iterator& other) const;
    };
    
    size_t size() const;
    iterator begin();
    iterator end();
};

class ComponentInfo {
public:
    String8 mName;
    List<String8> mRoles;
};

class IGraphicBufferProducer {
public:
    virtual void* asBinder() = 0;
};

class IOMXObserver;
class IMemory;
class BBinder {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
};
class IOMX;
class native_handle_t;

template<typename T> class sp {
public:
    sp();
    sp(T* other);
    T* operator->() const;
    T* get() const;
    T& operator*() const;
};

template<typename T>
T* interface_cast(void* binder);

class BnOMX : public BBinder {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
};

#define ALOGE(fmt, ...) \
    do { fprintf(stderr, "E/%s: " fmt "\n", "BnOMX", ##__VA_ARGS__); } while (0)

#define CHECK_OMX_INTERFACE(interface, data, reply) \
    do { } while (0)

#define TRESPASS() \
    do { } while (0)

status_t livesLocally(node_id node, pid_t pid);
status_t listNodes(List<ComponentInfo>* list);
status_t allocateNode(const char* name, sp<IOMXObserver> observer, node_id* node);
status_t freeNode(node_id node);
status_t sendCommand(node_id node, OMX_COMMANDTYPE cmd, OMX_S32 param);
status_t getParameter(node_id node, OMX_INDEXTYPE index, void* params, size_t size);
status_t setParameter(node_id node, OMX_INDEXTYPE index, void* params, size_t size);
status_t getConfig(node_id node, OMX_INDEXTYPE index, void* params, size_t size);
status_t setConfig(node_id node, OMX_INDEXTYPE index, void* params, size_t size);
status_t setInternalOption(node_id node, OMX_INDEXTYPE index, InternalOptionType type, void* params, size_t size);
status_t getState(node_id node, OMX_STATETYPE* state);
status_t enableGraphicBuffers(node_id node, OMX_U32 port_index, OMX_BOOL enable);
status_t getGraphicBufferUsage(node_id node, OMX_U32 port_index, OMX_U32* usage);
status_t useBuffer(node_id node, OMX_U32 port_index, sp<IMemory> params, buffer_id* buffer);
status_t useGraphicBuffer(node_id node, OMX_U32 port_index, sp<GraphicBuffer> graphicBuffer, buffer_id* buffer);
status_t updateGraphicBufferInMeta(node_id node, OMX_U32 port_index, sp<GraphicBuffer> graphicBuffer, buffer_id buffer);
status_t createInputSurface(node_id node, OMX_U32 port_index, sp<IGraphicBufferProducer>* bufferProducer);
status_t signalEndOfInputStream(node_id node);
status_t storeMetaDataInBuffers(node_id node, OMX_U32 port_index, OMX_BOOL enable);
status_t prepareForAdaptivePlayback(node_id node, OMX_U32 port_index, OMX_BOOL enable, OMX_U32 max_width, OMX_U32 max_height);
status_t configureVideoTunnelMode(node_id node, OMX_U32 port_index, OMX_BOOL tunneled, OMX_U32 audio_hw_sync, native_handle_t** sideband_handle);
status_t allocateBuffer(node_id node, OMX_U32 port_index, size_t size, buffer_id* buffer, void** buffer_data);
status_t allocateBufferWithBackup(node_id node, OMX_U32 port_index, sp<IMemory> params, buffer_id* buffer);
status_t freeBuffer(node_id node, OMX_U32 port_index, buffer_id buffer);
status_t fillBuffer(node_id node, buffer_id buffer);
status_t emptyBuffer(node_id node, buffer_id buffer, OMX_U32 range_offset, OMX_U32 range_length, OMX_U32 flags, OMX_TICKS timestamp);
status_t getExtensionIndex(node_id node, const char* parameter_name, OMX_INDEXTYPE* index);
bool isSecure(node_id node);