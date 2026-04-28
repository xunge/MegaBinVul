#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

extern string strRPCUserColonPass;
string DecodeBase64(const string& str);
bool TimingResistantEqual(const string& a, const string& b);

inline void trim(string& s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); }));
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end());
}

namespace boost {
    inline void trim(string& s) {
        ::trim(s);
    }
}