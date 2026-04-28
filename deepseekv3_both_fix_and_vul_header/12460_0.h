#include <cstddef>

extern int mValidContexts;
extern bool mValid;

class lcContext
{
public:
    ~lcContext();
    void DestroyResources();
};

class lcStringCache
{
public:
    void Reset();
};

class lcTexFont
{
public:
    void Reset();
};

class lcPiecesLibrary
{
public:
    void ReleaseBuffers(lcContext* context);
};

class lcView
{
public:
    static void DestroyResources(lcContext* context);
};

class lcViewSphere
{
public:
    static void DestroyResources(lcContext* context);
};

extern lcStringCache gStringCache;
extern lcTexFont gTexFont;

lcPiecesLibrary* lcGetPiecesLibrary();