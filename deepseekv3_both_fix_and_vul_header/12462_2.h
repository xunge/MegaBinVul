#include <vector>
#include <cstring>
#include <cmath>

typedef unsigned char quint8;

enum
{
    LC_PIXEL_FORMAT_A8,
    LC_TEXTURE_WRAPU,
    LC_TEXTURE_WRAPV,
    LC_TEXTURE_MIPMAPS,
    LC_TEXTURE_ANISOTROPIC
};

class Image
{
public:
    quint8* mData;
    void Allocate(int width, int height, int format);
};

class lcTexture;

class lcContext
{
public:
    static lcContext* GetGlobalOffscreenContext();
    void MakeCurrent();
    void Upload(lcContext* context);
};

class lcPiecesLibrary
{
public:
    static lcPiecesLibrary* GetPiecesLibrary();
    void QueueTextureUpload(lcTexture* texture);
};

class lcTexture
{
public:
    std::vector<Image> mImages;
    int mRefCount;
    int mFlags;
    void CreateGridTexture();
    void Upload(lcContext* context);
};

inline lcPiecesLibrary* lcGetPiecesLibrary()
{
    return lcPiecesLibrary::GetPiecesLibrary();
}