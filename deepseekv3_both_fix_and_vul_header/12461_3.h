#include <vector>

class lcTexture;

class Image {
public:
    void ResizePow2();
};

class lcContext {
public:
    static lcContext* GetGlobalOffscreenContext();
    void MakeCurrent();
};

class lcGetPiecesLibrary {
public:
    static lcGetPiecesLibrary* GetInstance();
    void QueueTextureUpload(lcTexture* texture);
};

class lcTexture {
public:
    std::vector<Image> mImages;
    int mFlags;

    bool Load(int Flags);
    void Upload(lcContext* Context);
};

lcGetPiecesLibrary* lcGetPiecesLibrary() {
    return lcGetPiecesLibrary::GetInstance();
}