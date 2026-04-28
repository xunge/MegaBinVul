#include <string>
#include <cstdint>
#include <ctime>
#include <iostream>

using std::string;
using int64 = int64_t;

namespace util {
class Status {
public:
    bool ok() const { return true; }
    static Status Ok() { return Status(); }
    static Status Unknown(const string&) { return Status(); }
};
} // namespace util

namespace googleapis {
namespace util {
class Status {
public:
    bool ok() const { return true; }
    operator ::util::Status() const { return ::util::Status::Ok(); }
};
} // namespace util
} // namespace googleapis

namespace googleapis_util {
bool Base64Unescape(const char*, size_t, string*) { return true; }
} // namespace googleapis_util

namespace OAuth2AuthorizationFlow {
class SimpleJsonData {
public:
    googleapis::util::Status Init(const string&) { return googleapis::util::Status(); }
    bool GetString(const string&, string*) { return true; }
    bool GetScalar(const string&, int*) { return true; }
};
} // namespace OAuth2AuthorizationFlow

class DateTime {
public:
    int64 ToEpochTime() const { return 0; }
};

template <typename T>
class Settable {
    T value_;
public:
    void set(const T& value) { value_ = value; }
};

class OAuth2Credential {
    Settable<string> refresh_token_;
    Settable<string> access_token_;
    Settable<int64> expiration_timestamp_secs_;
    string email_;
    bool email_verified_ = false;
public:
    util::Status UpdateFromString(const string& json);
};

bool safe_strto64(const char*, int64*) { return true; }

#define VLOG(level) std::cout
#define LOG(severity) std::cout
#define ERROR 1

inline util::Status StatusUnknown(const string& msg) { return util::Status::Unknown(msg); }
inline util::Status StatusOk() { return util::Status::Ok(); }