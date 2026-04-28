#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SMALL_BUFFER_MAX_SIZE 256
#define BUFFER_PADDING_SIZE 32
#define COMPILER 0
#define LIBFLAGS 1

extern char *pkgDataFlags[];
extern int32_t runCommand(const char *cmd);
extern int32_t pkg_generateLibraryFile(const char *targetDir, const char mode, const char *tempObjectFile);
extern char *uprv_strcpy(char *dest, const char *src);
extern size_t uprv_strlen(const char *str);
extern void *uprv_malloc(size_t size);
extern void uprv_free(void *ptr);

template<typename T>
class LocalMemory {
public:
    LocalMemory(T *ptr) : fPtr(ptr) {}
    ~LocalMemory() { uprv_free(fPtr); }
    bool isNull() const { return fPtr == NULL; }
    T *getAlias() const { return fPtr; }
private:
    T *fPtr;
};