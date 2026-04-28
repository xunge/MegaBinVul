#include <string>
#include <map>
#include <iostream>

#define SQLITE_OK 0
enum LogLevel { ERROR };

struct sqlite3;
extern "C" {
int sqlite3_open(const char*, sqlite3**);
int sqlite3_exec(sqlite3*, const char*, int (*)(void*,int,char**,char**), void*, char**);
int sqlite3_set_authorizer(sqlite3*, int (*)(void*,int,const char*,const char*,const char*,const char*), void*);
const char* sqlite3_errmsg(sqlite3*);
}

extern const std::map<std::string, std::string> kMemoryDBSettings;
extern void registerMathExtensions(sqlite3* db);
extern void registerStringExtensions(sqlite3* db);
extern void registerOperationExtensions(sqlite3* db);
extern void registerFilesystemExtensions(sqlite3* db);
extern void registerHashingExtensions(sqlite3* db);
extern void registerEncodingExtensions(sqlite3* db);
extern int sqliteAuthorizer(void*, int, const char*, const char*, const char*, const char*);
extern std::ostream& LOG(LogLevel level);
extern void requestShutdown(int rc);