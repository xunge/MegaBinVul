#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define LC_MAXPATH 260

enum class lcZipFileType {
    Official,
    Unofficial
};

class lcMemFile {
};

class lcTexture {
public:
    char* mName;
    char* mFileName;
    bool Load(lcMemFile& file);
    bool Load(const char* fileName);
};

class QMutexLocker {
public:
    QMutexLocker(pthread_mutex_t* mutex);
};

class lcZipFile {
public:
    bool ExtractFile(const char* fileName, lcMemFile& file);
};

class lcPiecesLibrary {
public:
    bool LoadTexture(lcTexture* Texture);
private:
    pthread_mutex_t mTextureMutex;
    lcZipFile* mZipFiles[2];
};