#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#define JNI_VERSION_1_6 0x00010006
#define ALOGV(...) printf(__VA_ARGS__)
#define ALOGE(...) fprintf(stderr, __VA_ARGS__)

typedef struct {
    int version;
    char* name;
    void* group;
} JavaVMAttachArgs;

typedef struct JavaVM {
    int (*AttachCurrentThread)(void**, JavaVMAttachArgs*);
    int (*DetachCurrentThread)(void);
} JavaVM;

extern JavaVM* vm;
extern void* callbackEnv;
extern bool sHaveCallbackThread;
extern pthread_t sCallbackThread;

typedef enum {
    ASSOCIATE_JVM,
    DISASSOCIATE_JVM
} bt_cb_thread_evt;

bool isCallbackThread(void);