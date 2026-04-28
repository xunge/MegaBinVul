#include <string>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

struct sqlite3;
struct sqlite3_stmt;

#define SQLITE_OK 0
#define SQLITE_ROW 100
#define SQLITE_OPEN_READONLY 0x00000001
#define SQLITE_OPEN_PRIVATECACHE 0x00040000
#define SQLITE_OPEN_NOMUTEX 0x00008000

struct Status {
    Status(int code, const std::string& message) {}
    Status() {}
    bool ok() const { return true; }
};

struct TableRows {};

Status pathExists(const fs::path& path) {
    return Status();
}

const char* getStringForSQLiteReturnCode(int code) {
    return "";
}

int sqliteAuthorizer(void*, int, const char*, const char*, const char*, const char*) {
    return 0;
}

const char* getSystemVFS(bool) {
    return nullptr;
}

Status genSqliteTableRow(sqlite3_stmt*, TableRows&, const fs::path&) {
    return Status();
}

int sqlite3_open_v2(const char*, sqlite3**, int, const char*) { return 0; }
int sqlite3_set_authorizer(sqlite3*, int(*)(void*,int,const char*,const char*,const char*,const char*), void*) { return 0; }
int sqlite3_prepare_v2(sqlite3*, const char*, int, sqlite3_stmt**, const char**) { return 0; }
int sqlite3_step(sqlite3_stmt*) { return 0; }
int sqlite3_finalize(sqlite3_stmt*) { return 0; }
int sqlite3_close(sqlite3*) { return 0; }
const char* sqlite3_errmsg(sqlite3*) { return ""; }

#define VLOG(level) if (1) {} else std::cout