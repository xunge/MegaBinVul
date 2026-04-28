#include <stdint.h>
#include <cstddef>

typedef uint32_t AP4_UI32;
typedef uint64_t AP4_UI64;
typedef int32_t  AP4_SI32;
typedef uint64_t AP4_Position;
typedef uint64_t AP4_LargeSize;
typedef unsigned int AP4_Ordinal;
typedef unsigned int AP4_Cardinal;

#define AP4_ATOM_HEADER_SIZE 8
#define AP4_ATOM_TYPE_MOOF   0x6D6F6F66
#define AP4_ATOM_TYPE_TRAF   0x74726166
#define AP4_ATOM_TYPE_TFHD   0x74666864
#define AP4_ATOM_TYPE_TRAK   0x7472616B
#define AP4_ATOM_TYPE_TKHD   0x746B6864
#define AP4_ATOM_TYPE_MVEX   0x6D766578
#define AP4_ATOM_TYPE_TREX   0x74726578
#define AP4_ATOM_TYPE_TRUN   0x7472756E
#define AP4_ATOM_TYPE_MDAT   0x6D646174
#define AP4_ATOM_TYPE_TFRA   0x74667261

#define AP4_TFHD_FLAG_BASE_DATA_OFFSET_PRESENT   0x000001
#define AP4_TFHD_FLAG_DEFAULT_SAMPLE_SIZE_PRESENT 0x000008
#define AP4_TRUN_FLAG_SAMPLE_SIZE_PRESENT        0x000100

#define AP4_DYNAMIC_CAST(type, obj) dynamic_cast<type*>(obj)
#define AP4_FAILED(result) ((result).code != 0)
#define AP4_SUCCESS {0}

struct AP4_Result {
    int code;
};

struct AP4_ByteStream {
    AP4_Result Tell(AP4_Position& position);
    AP4_Result Write(const void* data, AP4_UI32 size);
    AP4_Result WriteUI32(AP4_UI32 value);
    AP4_Result WriteUI64(AP4_UI64 value);
    AP4_Result Seek(AP4_Position position);
};

struct AP4_DataBuffer {
    const void* GetData() const;
    AP4_UI32 GetDataSize() const;
};

struct AP4_Atom {
    virtual ~AP4_Atom() {}
    virtual AP4_UI32 GetType() const = 0;
    virtual AP4_Result Write(AP4_ByteStream& output) = 0;
    virtual AP4_UI64 GetSize() const = 0;
    virtual AP4_Atom* GetChild(AP4_UI32 type, unsigned int index = 0) = 0;
};

template<typename T>
struct AP4_List {
    struct Item {
        Item* GetNext();
        T* GetData();
    };
    Item* FirstItem();
};

template<typename T>
struct AP4_Array {
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    void Append(T item);
    T Item(unsigned int index) const;
    unsigned int ItemCount() const;
};

struct AP4_AtomLocator {
    AP4_Atom* m_Atom;
    AP4_UI64  m_Offset;
};

struct AP4_ContainerAtom : public AP4_Atom {
    AP4_List<AP4_Atom>& GetChildren();
};

struct AP4_MoovAtom : public AP4_ContainerAtom {};
struct AP4_TrakAtom : public AP4_ContainerAtom {};
struct AP4_TkhdAtom {
    AP4_UI32 GetTrackId() const;
};
struct AP4_TrexAtom {
    AP4_UI32 GetTrackId() const;
};
struct AP4_TfhdAtom {
    AP4_UI32 GetFlags() const;
    AP4_UI32 GetTrackId() const;
    void SetBaseDataOffset(AP4_UI64 offset);
    void SetDefaultSampleSize(AP4_UI32 size);
};
struct AP4_TrunAtom {
    struct Entry {
        AP4_UI32 sample_size;
    };
    AP4_Array<Entry>& GetEntries();
    AP4_Array<Entry>& UseEntries();
    void SetDataOffset(AP4_SI32 offset);
    AP4_UI32 GetFlags() const;
};
struct AP4_TfraAtom {
    struct Entry {
        AP4_UI64 m_MoofOffset;
    };
    AP4_Array<Entry>& GetEntries();
    AP4_Cardinal GetEntryCount() const;
};
struct AP4_SidxAtom {
    struct Reference {
        AP4_UI32 m_ReferencedSize;
    };
    AP4_Array<Reference>& GetReferences();
    AP4_Array<Reference>& UseReferences();
    AP4_UI64 GetSize() const;
    void SetFirstOffset(AP4_UI64 offset);
};
struct AP4_Sample {
    AP4_Result ReadData(AP4_DataBuffer& buffer);
};
struct AP4_FragmentSampleTable {
    AP4_UI32 GetSampleCount() const;
    AP4_Result GetSample(AP4_UI32 index, AP4_Sample& sample);
};
struct AP4_MovieFragment {
    AP4_MovieFragment(AP4_ContainerAtom* moof);
    AP4_Result CreateSampleTable(AP4_MoovAtom* moov, AP4_UI32 track_id, AP4_ByteStream* input, AP4_UI64 moof_offset, AP4_UI64 mdat_payload_offset, AP4_UI32 sample_description_index, AP4_FragmentSampleTable*& sample_table);
};
struct AP4_Processor {
    struct FragmentHandler {
        virtual ~FragmentHandler() {}
        virtual AP4_Result ProcessFragment() = 0;
        virtual AP4_Result PrepareForSamples(AP4_FragmentSampleTable* sample_table) = 0;
        virtual AP4_Result ProcessSample(AP4_DataBuffer& input, AP4_DataBuffer& output) = 0;
        virtual void FinishFragment() = 0;
    };
    FragmentHandler* CreateFragmentHandler(AP4_TrakAtom* trak, AP4_TrexAtom* trex, AP4_ContainerAtom* traf, AP4_ByteStream& input, AP4_UI64 offset);
    AP4_Result ProcessFragments(AP4_MoovAtom* moov, AP4_List<AP4_AtomLocator>& atoms, AP4_ContainerAtom* mfra, AP4_SidxAtom* sidx, AP4_Position sidx_position, AP4_ByteStream& input, AP4_ByteStream& output);
};
struct FragmentMapEntry {
    AP4_UI64 before;
    AP4_UI64 after;
};
const FragmentMapEntry* FindFragmentMapEntry(const AP4_Array<FragmentMapEntry>& fragment_map, AP4_UI64 moof_offset);