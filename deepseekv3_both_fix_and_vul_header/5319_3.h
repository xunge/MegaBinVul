#include <stdint.h>
#include <string>
#include <map>

typedef uint32_t int32u;
typedef uint64_t int64u;
typedef uint8_t int8u;

namespace Elements {
    const uint32_t W3DI = 0x57334449;
    const uint32_t SMV0 = 0x534D5630;
    const uint32_t SMV0_xxxx = 0x534D5630;
    const uint32_t riff = 0x72696666;
    const uint32_t WAVE_data = 0x64617461;
    const uint32_t FORM = 0x464F524D;
    const uint32_t MThd = 0x4D546864;
    const uint32_t RIFF = 0x52494646;
    const uint32_t RF64 = 0x52463634;
    const uint32_t WAVE_ds64 = 0x64733634;
    const uint32_t LIST = 0x4C495354;
    const uint32_t ON2_ = 0x4F4E3220;
    const uint32_t ON2f = 0x4F4E3266;
    const uint32_t AVI_ = 0x41564920;
    const uint32_t WAVE = 0x57415645;
    const uint32_t AIFF_SSND = 0x53534E44;
}

class Ztring {
public:
    std::string From_CC4(uint32_t);
};

class File_Riff {
public:
    uint32_t Element_Level;
    uint64_t File_Offset;
    uint32_t Buffer_Size;
    uint64_t File_Size;
    uint8_t* Buffer;
    uint32_t Buffer_Offset;
    uint32_t SMV_BlockSize;
    bool IsWave64;
    bool IsBigEndian;
    bool IsNotWordAligned;
    bool IsNotWordAligned_Tested;
    bool IsRIFF64;
    bool IsWaveBroken;
    uint32_t Alignement_ExtraByte;
    uint64_t Buffer_DataToParse_Begin;
    uint64_t Buffer_DataToParse_End;
    uint64_t WAVE_data_Size;
    uint64_t movi_Size;
    bool rec__Present;
    uint64_t Element_Offset;
    uint64_t Element_Size;
    std::string File_Name;
    std::map<uint32_t, struct StreamInfo> Stream_Structure;
    std::map<uint32_t, struct StreamInfo>::iterator Stream_Structure_Temp;
    
    enum StreamType {
        Stream_General
    };
    
    uint64_t Element_TotalSize_Get();
    void Header_Parse();
    void Header_Fill_Code(uint32_t code, const std::string& name);
    void Header_Fill_Size(uint64_t size);
    void Get_C4(uint32_t& name, const char* description);
    void Get_L4(uint32_t& size, const char* description);
    void Get_B4(uint32_t& size, const char* description);
    void Get_L8(uint64_t& size, const char* description);
    void Skip_XX(uint32_t size, const char* description);
    void Element_WaitForMoreData();
    void Fill(StreamType stream, int param, const char* name, const char* value);
    void Fill(StreamType stream, int param, const char* name, const std::string& value);
    void Param_Info1(uint64_t size);
    uint32_t CC4(const uint8_t* buffer);
    uint32_t LittleEndian2int32u(const uint8_t* buffer);
    uint64_t LittleEndian2int64u(const uint8_t* buffer);
};

struct StreamInfo {
    uint64_t Size;
};

uint32_t File_Riff::CC4(const uint8_t* buffer) {
    return (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
}

uint32_t File_Riff::LittleEndian2int32u(const uint8_t* buffer) {
    return buffer[0] | (buffer[1] << 8) | (buffer[2] << 16) | (buffer[3] << 24);
}

uint64_t File_Riff::LittleEndian2int64u(const uint8_t* buffer) {
    return (uint64_t)buffer[0] | ((uint64_t)buffer[1] << 8) | ((uint64_t)buffer[2] << 16) | ((uint64_t)buffer[3] << 24) |
           ((uint64_t)buffer[4] << 32) | ((uint64_t)buffer[5] << 40) | ((uint64_t)buffer[6] << 48) | ((uint64_t)buffer[7] << 56);
}