#include <stdint.h>
#include <stddef.h>

typedef uint64_t UDATA;
typedef uint32_t U_32;
typedef int32_t IDATA;
typedef int32_t I_32;
typedef uint8_t BOOLEAN;

#define TRUE 1
#define FALSE 0

struct J9PortLibrary;
struct J9JavaVM {
    uint32_t sigFlags;
    void* runtimeFlagsMutex;
    uint32_t runtimeFlags;
    void* systemThreadGroupRef;
};
struct J9VMThread;
struct JavaVM;

struct J9JavaVMAttachArgs {
    I_32 version;
    const char* name;
    void* group;
};

#define J9_SIG_XRS_ASYNC 0x1
#define J9_RUNTIME_EXIT_STARTED 0x1
#define J9_RUNTIME_INITIALIZED 0x2
#define JNI_VERSION_1_8 0x00010008
#define JNI_OK 0
#define JNI_ERR (-1)

#define J9_PRIVATE_FLAGS_DAEMON_THREAD 0x1
#define J9_PRIVATE_FLAGS_SYSTEM_THREAD 0x2
#define J9_PRIVATE_FLAGS_ATTACHED_THREAD 0x4

#define PORT_ACCESS_FROM_JAVAVM(vm)
#define J9_ARE_ANY_BITS_SET(value, bits) ((value) & (bits))
#define J9_ARE_NO_BITS_SET(value, bits) (!((value) & (bits)))

extern I_32 j9sig_map_portlib_signal_to_os_signal(U_32 gpType);
extern IDATA internalAttachCurrentThread(struct J9JavaVM* vm, struct J9VMThread** vmThread, struct J9JavaVMAttachArgs* attachArgs, UDATA flags, void* thread);
extern void signalDispatch(struct J9VMThread* vmThread, I_32 signal);
extern void DetachCurrentThread(struct JavaVM* vm);
extern void* omrthread_self();
extern void omrthread_monitor_enter(void* mutex);
extern void omrthread_monitor_exit(void* mutex);
extern void issueReadBarrier();

typedef struct J9JavaVM J9JavaVM;
typedef struct J9VMThread J9VMThread;
typedef struct J9JavaVMAttachArgs J9JavaVMAttachArgs;
typedef struct JavaVM JavaVM;