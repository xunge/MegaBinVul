#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

extern map<long long, long> sessionMap;
extern string getLogin();
extern string getHeader(string username);
extern string getEmptyCalendar();
extern string getFooter();
extern long makeUser(string username, string password);
extern void logout(long uid);
extern long long login(string username, string password);
extern long makeGroup(long uid, string groupName);
extern long groupIdByName(string groupName);
extern long userIdByName(string username);
extern bool addToGroup(long uid, long addedId, long groupId, bool admin);
extern long makeEvent(long uid, string eventName, time_t eventTime, long groupId = -1, bool withGroup = false);
extern void renameEvent(long uid, long eventId, string eventName);
extern void rescheduleEvent(long uid, long eventId, time_t eventTime);
extern string getResponseHeader(string status, map<string, string>* headers, size_t bodySize);