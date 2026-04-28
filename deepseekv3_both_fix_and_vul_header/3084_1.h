#include <map>
#include <string>
#include <algorithm>

using namespace std;

extern string strRPCUserColonPass;
string DecodeBase64(const string& str);

namespace boost {
    inline void trim(string& str) {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) { return !std::isspace(ch); }));
        str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) { return !std::isspace(ch); }).base(), str.end());
    }
}