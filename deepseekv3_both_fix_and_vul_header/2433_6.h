#include <stdint.h>
#include <stdlib.h>

typedef int AP4_Result;
typedef uint32_t AP4_UI32;
typedef uint64_t AP4_UI64;
typedef uint64_t AP4_Position;
typedef uint32_t AP4_Size;
typedef uint64_t AP4_LargeSize;
typedef unsigned int AP4_Cardinal;
typedef unsigned int AP4_Ordinal;

class AP4_ByteStream;
class ProgressListener;
class AP4_AtomFactory;
class AP4_AtomParent;
class TrackHandler;
class AP4_TrakAtom;
class AP4_MoovAtom;
class AP4_AtomLocator;
class AP4_ContainerAtom;
class AP4_SidxAtom;
class AP4_Atom;

template<typename T>
class AP4_List {
public:
    class Item {
    public:
        T* GetData();
        Item* GetNext();
    };
    void DeleteReferences();
    void SetItemCount(AP4_Cardinal count);
    AP4_Cardinal ItemCount() const;
    Item* FirstItem();
    void Add(T* item);
    void Clear();
    template<typename Functor>
    void Apply(const Functor& func);
    bool Get(AP4_Ordinal index, T*& item);
};

template<typename T>
class AP4_Array {
public:
    void Append(const T& item);
    AP4_Ordinal ItemCount() const;
    T& operator[](AP4_Ordinal index);
    void SetItemCount(AP4_Cardinal count);
    void Clear();
};

class AP4_ByteStream {
public:
    virtual ~AP4_ByteStream() {}
    virtual AP4_Result Tell(AP4_UI64& offset) = 0;
    virtual AP4_Result Seek(AP4_Position position) = 0;
    virtual AP4_Result Write(const void* buffer, AP4_Size bytesToWrite) = 0;
    virtual AP4_Result WriteUI32(AP4_UI32 value) = 0;
    virtual AP4_Result WriteUI64(AP4_UI64 value) = 0;
};

class AP4_Atom {
public:
    virtual ~AP4_Atom() {}
    virtual AP4_UI32 GetType() const = 0;
    virtual AP4_UI64 GetSize() const = 0;
    virtual AP4_Result Write(AP4_ByteStream& stream) = 0;
    virtual AP4_Atom* FindChild(const char* path) = 0;
};

class AP4_ContainerAtom : public AP4_Atom {
public:
    AP4_List<AP4_TrakAtom>& GetTrakAtoms();
};

class AP4_MoovAtom : public AP4_ContainerAtom {
public:
    AP4_UI32 GetId() const;
};

class AP4_TrakAtom : public AP4_Atom {
public:
    AP4_UI32 GetId() const;
    void AdjustChunkOffsets(AP4_UI64 offset);
};

class AP4_SidxAtom : public AP4_Atom {
};

class AP4_AtomParent {
public:
    void AddChild(AP4_Atom* atom);
    void RemoveChild(AP4_Atom* atom);
    AP4_List<AP4_Atom>& GetChildren();
};

class AP4_AtomFactory {
public:
    AP4_Result CreateAtomFromStream(AP4_ByteStream& stream, AP4_Atom*& atom);
};

class AP4_DataBuffer {
public:
    const unsigned char* GetData() const;
    AP4_Size GetDataSize() const;
};

class AP4_Sample {
public:
    AP4_UI64 GetOffset() const;
    AP4_Size GetSize() const;
    AP4_Result ReadData(AP4_DataBuffer& buffer);
};

class AP4_AtomSampleTable {
public:
    AP4_AtomSampleTable(AP4_ContainerAtom* stbl, AP4_ByteStream& stream);
    AP4_UI32 GetSampleCount() const;
    void GetSample(AP4_Ordinal index, AP4_Sample& sample);
    void GetChunkForSample(AP4_Ordinal sampleIndex, AP4_Ordinal& chunkIndex, AP4_Ordinal& skip, AP4_Ordinal& sdesc);
    void SetChunkOffset(AP4_Ordinal chunkIndex, AP4_Position offset);
    void SetSampleSize(AP4_Ordinal sampleIndex, AP4_Size size);
};

class AP4_AtomLocator {
public:
    AP4_AtomLocator(AP4_Atom* atom, AP4_UI64 offset);
};

class AP4_SampleLocator {
public:
    AP4_UI32 m_TrakIndex;
    AP4_AtomSampleTable* m_SampleTable;
    AP4_Ordinal m_SampleIndex;
    AP4_Ordinal m_ChunkIndex;
    AP4_Sample m_Sample;
};

class AP4_SampleCursor {
public:
    AP4_SampleLocator m_Locator;
    bool m_EndReached;
};

class ProgressListener {
public:
    virtual void OnProgress(unsigned int current, unsigned int total) = 0;
};

class TrackHandler {
public:
    virtual AP4_Size GetProcessedSampleSize(const AP4_Sample& sample) = 0;
    virtual AP4_Result ProcessSample(const AP4_DataBuffer& data_in, AP4_DataBuffer& data_out) = 0;
    virtual void ProcessTrack() = 0;
};

class ExternalTrackData {
public:
    AP4_UI32 m_TrackId;
    AP4_ByteStream* m_MediaData;
};

class AP4_AtomSizeAdder {
public:
    AP4_AtomSizeAdder(AP4_UI64& size);
    void operator()(AP4_Atom* atom) const;
private:
    AP4_UI64& m_Size;
};

class AP4_AtomListWriter {
public:
    AP4_AtomListWriter(AP4_ByteStream& stream);
    void operator()(AP4_Atom* atom) const;
private:
    AP4_ByteStream& m_Stream;
};

class AP4_Processor {
public:
    AP4_Result Process(AP4_ByteStream& input, 
                      AP4_ByteStream& output,
                      AP4_ByteStream* fragments,
                      ProgressListener* listener,
                      AP4_AtomFactory& atom_factory);
protected:
    AP4_Result Initialize(AP4_AtomParent& top_level, AP4_ByteStream& input);
    AP4_Result Finalize(AP4_AtomParent& top_level);
    TrackHandler* CreateTrackHandler(AP4_TrakAtom* trak);
    AP4_Result ProcessFragments(AP4_MoovAtom* moov,
                              AP4_List<AP4_AtomLocator>& frags,
                              AP4_ContainerAtom* mfra,
                              AP4_SidxAtom* sidx,
                              AP4_Position sidx_position,
                              AP4_ByteStream& input,
                              AP4_ByteStream& output);
    AP4_Array<TrackHandler*> m_TrackHandlers;
    AP4_Array<AP4_UI32> m_TrackIds;
    AP4_List<ExternalTrackData> m_ExternalTrackData;
};

#define AP4_ATOM_TYPE_MDAT 0x6D646174
#define AP4_ATOM_TYPE_MOOV 0x6D6F6F76
#define AP4_ATOM_TYPE_MFRA 0x6D667261
#define AP4_ATOM_TYPE_SIDX 0x73696478
#define AP4_ATOM_TYPE_SSIX 0x73736978
#define AP4_ATOM_TYPE_MOOF 0x6D6F6F66
#define AP4_ATOM_HEADER_SIZE 8

#define AP4_SUCCEEDED(result) ((result) == AP4_SUCCESS)
#define AP4_FAILED(result) ((result) != AP4_SUCCESS)
#define AP4_SUCCESS 0
#define AP4_DYNAMIC_CAST(type, ptr) dynamic_cast<type*>(ptr)