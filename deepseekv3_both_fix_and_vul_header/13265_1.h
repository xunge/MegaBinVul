#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLATFORM_DESKTOP
#define LOG_WARNING 1

typedef struct {
    struct {
        struct {
            struct {
                void *clazz;
                void *vm;
            } *activity;
        } Android;
    } app;
} CORE;

void TRACELOG(int logLevel, const char *message);
void *RL_CALLOC(size_t size, size_t count);
void RL_FREE(void *ptr);

// Forward declarations for JNI types
typedef struct JNIEnv_ JNIEnv;
typedef struct JavaVM_ JavaVM;
typedef void* jobject;
typedef void* jclass;
typedef void* jstring;
typedef void* jmethodID;
typedef void* jfieldID;

// JNI function table stubs
struct JNINativeInterface_;
struct JNIInvokeInterface_;

struct JNIEnv_ {
    const struct JNINativeInterface_ *functions;
};

struct JavaVM_ {
    const struct JNIInvokeInterface_ *functions;
};