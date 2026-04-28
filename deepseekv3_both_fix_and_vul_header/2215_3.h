#include <cstdint>
#include <vector>
#include <memory>

typedef int32_t sal_Int32;
typedef uint8_t sal_uInt8;
typedef int8_t sal_Int8;
typedef bool sal_Bool;
const sal_Bool sal_False = false;
const sal_Bool sal_True = true;

#define DBG_ASSERT(cond, msg)
#define RTL_LOGFILE_CONTEXT(var, msg)
#define RTL_LOGFILE_CONTEXT_TRACE(var, msg)

namespace uno {
    template<typename T> class Reference {
        T* p;
    public:
        Reference() : p(nullptr) {}
        bool is() const { return p != nullptr; }
        void clear() { p = nullptr; }
        T* operator->() { return p; }
    };

    class Exception {};
    
    template<typename T> class Sequence {
        T* data;
        sal_Int32 length;
    public:
        Sequence(sal_Int32 len) : length(len) {}
        const T* getConstArray() const { return data; }
    };
}

namespace io {
    class XInputStream {
    public:
        virtual sal_Int32 readBytes(uno::Sequence<sal_Int8>&, sal_Int32) = 0;
    };
}

class SvStream {
public:
    virtual void Write(const void*, size_t) = 0;
    virtual void Seek(size_t) = 0;
    virtual ~SvStream() = default;
};

class SvMemoryStream : public SvStream {
public:
    SvMemoryStream(sal_Int32, sal_Int32) {}
    void Write(const void*, size_t) override {}
    void Seek(size_t) override {}
};

namespace utl {
    class UcbStreamHelper {
    public:
        static SvStream* CreateStream(uno::Reference<io::XInputStream>) { return nullptr; }
    };
}

class XInterface {};

struct GraphicContainer {
    uno::Reference<io::XInputStream> GetGraphicStream(uno::Reference<XInterface>, const char**) { return {}; }
    void InsertGraphicStream(uno::Reference<io::XInputStream>, const char*, const char*) {}
};

struct EmbeddedObjectRef_Impl {
    GraphicContainer* pContainer;
    sal_Bool bNeedUpdate;
    const char* aPersistName;
    const char* aMediaType;
    sal_Int32 nViewAspect;
};

class EmbeddedObjectRef {
private:
    EmbeddedObjectRef_Impl* mpImp;
    uno::Reference<XInterface> mxObj;
public:
    SvStream* GetGraphicStream(sal_Bool bUpdate) const;
    uno::Reference<io::XInputStream> GetGraphicReplacementStream(sal_Int32, const uno::Reference<XInterface>&, const char**) const;
};