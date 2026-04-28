#include <stdbool.h>

struct lcContext {
    static lcContext* GetGlobalOffscreenContext();
    void MakeCurrent();
    void DestroyVertexBuffer(void* buffer);
    void DestroyIndexBuffer(void* buffer);
};

class lcPiecesLibrary {
public:
    void ReleaseBuffers();
    void ReleaseBuffers(lcContext* Context);

private:
    void* mVertexBuffer;
    void* mIndexBuffer;
    bool mBuffersDirty;
};