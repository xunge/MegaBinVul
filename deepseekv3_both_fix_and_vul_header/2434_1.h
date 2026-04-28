#include <stddef.h>

typedef int AP4_Result;
class AP4_AtomInspector {
public:
    void AddField(const char* name, int value);
    void AddField(const char* name, const char* value);
    void AddField(const char* name, int value, int hint);
    void AddField(const char* name, const void* data, size_t size);
    static const int HINT_HEX;
};
const int AP4_AtomInspector::HINT_HEX = 0;

class AP4_AvccAtom {
public:
    AP4_Result InspectFields(AP4_AtomInspector& inspector);
private:
    int m_ConfigurationVersion;
    int m_Profile;
    int m_ProfileCompatibility;
    int m_Level;
    int m_NaluLengthSize;
    class ParameterList {
    public:
        unsigned int ItemCount();
        class Parameter {
        public:
            const void* GetData();
            size_t GetDataSize();
        };
        Parameter operator[](unsigned int);
    };
    ParameterList m_SequenceParameters;
    ParameterList m_PictureParameters;
    const char* GetProfileName(int profile);
};

constexpr AP4_Result AP4_SUCCESS = 0;