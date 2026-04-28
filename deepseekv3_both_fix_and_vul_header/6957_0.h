#include <string>
#include <map>
#include <iostream>
using namespace std;

extern map<long long, long> sessionMap;
string getLogin();
string userNameById(long uid);
string getHeader(string username);
string getEmptyCalendar();
string getFooter();
string getEventsJson(long uid);
string getResponseHeader(string status, map<string, string>* headers, size_t bodySize);