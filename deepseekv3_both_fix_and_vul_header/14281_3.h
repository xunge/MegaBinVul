#include <algorithm>

#define MAPITEMTYPE_ENVPOINTS 0
#define MAPITEMTYPE_ENVELOPE 0

template<typename T>
class array
{
public:
    void clear();
    void add(const T& item);
};

struct CEnvPoint
{
    int m_Time;
    int m_Curvetype;
    int m_aValues[4];
    int m_aInTangentdx[4];
    int m_aInTangentdy[4];
    int m_aOutTangentdx[4];
    int m_aOutTangentdy[4];
};

struct CEnvPoint_v1
{
    int m_Time;
    int m_Curvetype;
    int m_aValues[4];
};

struct CMapItemEnvelope
{
    int m_Version;
    int m_NumPoints;
    int m_StartPoint;
    int m_Channels;
};

class CMap
{
public:
    void GetType(int Type, int* pStart, int* pNum) const;
    void* GetItem(int Index, int* pType, int* pID) const;
};

class CLayers
{
public:
    const CMap* Map() const;
};

class CMapLayers
{
public:
    void LoadEnvPoints(const CLayers* pLayers, array<CEnvPoint>& lEnvPoints);
};

template<typename T>
T minimum(T a, T b)
{
    return std::min(a, b);
}