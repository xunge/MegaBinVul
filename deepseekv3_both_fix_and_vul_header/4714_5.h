#include <stdint.h>
#include <memory>
#include <string>

class CFX_ByteString : public std::string {
public:
    bool IsEmpty() const { return empty(); }
    const uint8_t* GetData() const;
    uint32_t GetSize() const;
    const CFX_ByteString& GetImageDecoder() const;
    const class CPDF_Dictionary* GetImageParam() const;
};

class CPDF_Dictionary {
public:
    int GetIntegerBy(const char* key, int default_val) const;
};

class CPDF_ModuleMgr {
public:
    static CPDF_ModuleMgr* Get();
    class CCodec_JpegModule* GetJpegModule();
    class CodecModule* GetCodecModule();
};

class CCodec_JpegModule {
public:
    class DecoderInterface* CreateDecoder(const uint8_t* src_data, uint32_t src_size, uint32_t width, uint32_t height, uint32_t nComponents, int transform);
    bool LoadInfo(const uint8_t* src_data, uint32_t src_size, uint32_t& width, uint32_t& height, int& comps, int& bpc, int& bTransform);
};

class CodecModule {
public:
    class BasicModule* GetBasicModule();
};

class BasicModule {
public:
    class DecoderInterface* CreateRunLengthDecoder(const uint8_t* src_data, uint32_t src_size, uint32_t width, uint32_t height, uint32_t nComponents, uint32_t bpc);
};

class CFX_DIBitmap {
public:
    bool Create(uint32_t width, uint32_t height, int format);
};

class FX_SAFE_UINT32 {
public:
    FX_SAFE_UINT32(uint32_t value);
    bool IsValid() const;
    uint32_t ValueOrDie() const;
};

class DecoderInterface {
public:
    virtual uint32_t GetBPC() const = 0;
    virtual uint32_t CountComps() const = 0;
    virtual uint32_t GetWidth() const = 0;
    virtual ~DecoderInterface() = default;
};

enum PDFCS_FAMILY {
    PDFCS_LAB
};

enum FXDIB_Format {
    FXDIB_1bppMask,
    FXDIB_1bppRgb
};

#define FX_BOOL int
#define FALSE 0
#define TRUE 1

#define FX_Free(ptr) free(ptr)

class ColorSpaceInterface {
public:
    virtual uint32_t CountComponents() const = 0;
    virtual ~ColorSpaceInterface() = default;
};

class CPDF_DIBSource {
public:
    int CreateDecoder();
    void* GetDecodeAndMaskArray(bool bDefaultDecode, bool bColorKey);
    void LoadJpxBitmap();
    static FX_SAFE_UINT32 CalculatePitch8(uint32_t bpc, uint32_t nComponents, uint32_t width);

private:
    CFX_ByteString* m_pStreamAcc;
    bool m_bDoBpcCheck;
    uint32_t m_bpc;
    uint32_t m_Width;
    uint32_t m_Height;
    uint32_t m_nComponents;
    void* m_pCompData;
    ColorSpaceInterface* m_pColorSpace;
    PDFCS_FAMILY m_Family;
    bool m_bDefaultDecode;
    bool m_bColorKey;
    std::unique_ptr<DecoderInterface> m_pDecoder;
    std::unique_ptr<CFX_DIBitmap> m_pCachedBitmap;
    int m_Status;
    bool m_bImageMask;
};

DecoderInterface* FPDFAPI_CreateFaxDecoder(const uint8_t* src_data, uint32_t src_size, uint32_t width, uint32_t height, const CPDF_Dictionary* pParams);
DecoderInterface* FPDFAPI_CreateFlateDecoder(const uint8_t* src_data, uint32_t src_size, uint32_t width, uint32_t height, uint32_t nComponents, uint32_t bpc, const CPDF_Dictionary* pParams);