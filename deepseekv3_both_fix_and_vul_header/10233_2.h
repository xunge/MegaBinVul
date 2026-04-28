#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct OutStruct {
    char *filename;
};

enum {
    VAR_EFFECTIVE_URL,
    VAR_HTTP_CODE,
    VAR_HTTP_CODE_PROXY,
    VAR_HEADER_SIZE,
    VAR_REQUEST_SIZE,
    VAR_NUM_CONNECTS,
    VAR_REDIRECT_COUNT,
    VAR_REDIRECT_TIME,
    VAR_TOTAL_TIME,
    VAR_NAMELOOKUP_TIME,
    VAR_CONNECT_TIME,
    VAR_APPCONNECT_TIME,
    VAR_PRETRANSFER_TIME,
    VAR_STARTTRANSFER_TIME,
    VAR_SIZE_UPLOAD,
    VAR_SIZE_DOWNLOAD,
    VAR_SPEED_DOWNLOAD,
    VAR_SPEED_UPLOAD,
    VAR_CONTENT_TYPE,
    VAR_FTP_ENTRY_PATH,
    VAR_REDIRECT_URL,
    VAR_SSL_VERIFY_RESULT,
    VAR_PROXY_SSL_VERIFY_RESULT,
    VAR_EFFECTIVE_FILENAME,
    VAR_PRIMARY_IP,
    VAR_PRIMARY_PORT,
    VAR_LOCAL_IP,
    VAR_LOCAL_PORT,
    VAR_HTTP_VERSION,
    VAR_SCHEME
};

struct var {
    const char *name;
    int id;
};

static const struct var replacements[] = {
    {"url_effective", VAR_EFFECTIVE_URL},
    {"http_code", VAR_HTTP_CODE},
    {"http_connect", VAR_HTTP_CODE_PROXY},
    {"header_size", VAR_HEADER_SIZE},
    {"request_size", VAR_REQUEST_SIZE},
    {"num_connects", VAR_NUM_CONNECTS},
    {"redirect_count", VAR_REDIRECT_COUNT},
    {"redirect_time", VAR_REDIRECT_TIME},
    {"total_time", VAR_TOTAL_TIME},
    {"namelookup_time", VAR_NAMELOOKUP_TIME},
    {"connect_time", VAR_CONNECT_TIME},
    {"appconnect_time", VAR_APPCONNECT_TIME},
    {"pretransfer_time", VAR_PRETRANSFER_TIME},
    {"starttransfer_time", VAR_STARTTRANSFER_TIME},
    {"size_upload", VAR_SIZE_UPLOAD},
    {"size_download", VAR_SIZE_DOWNLOAD},
    {"speed_download", VAR_SPEED_DOWNLOAD},
    {"speed_upload", VAR_SPEED_UPLOAD},
    {"content_type", VAR_CONTENT_TYPE},
    {"ftp_entry_path", VAR_FTP_ENTRY_PATH},
    {"redirect_url", VAR_REDIRECT_URL},
    {"ssl_verify_result", VAR_SSL_VERIFY_RESULT},
    {"proxy_ssl_verify_result", VAR_PROXY_SSL_VERIFY_RESULT},
    {"filename_effective", VAR_EFFECTIVE_FILENAME},
    {"primary_ip", VAR_PRIMARY_IP},
    {"primary_port", VAR_PRIMARY_PORT},
    {"local_ip", VAR_LOCAL_IP},
    {"local_port", VAR_LOCAL_PORT},
    {"http_version", VAR_HTTP_VERSION},
    {"scheme", VAR_SCHEME},
    {NULL, 0}
};

#define FALSE false
#define TRUE true

typedef void CURL;
#define CURLE_OK 0
#define CURLINFO_EFFECTIVE_URL 1
#define CURLINFO_RESPONSE_CODE 2
#define CURLINFO_HTTP_CONNECTCODE 3
#define CURLINFO_HEADER_SIZE 4
#define CURLINFO_REQUEST_SIZE 5
#define CURLINFO_NUM_CONNECTS 6
#define CURLINFO_REDIRECT_COUNT 7
#define CURLINFO_REDIRECT_TIME 8
#define CURLINFO_TOTAL_TIME 9
#define CURLINFO_NAMELOOKUP_TIME 10
#define CURLINFO_CONNECT_TIME 11
#define CURLINFO_APPCONNECT_TIME 12
#define CURLINFO_PRETRANSFER_TIME 13
#define CURLINFO_STARTTRANSFER_TIME 14
#define CURLINFO_SIZE_UPLOAD 15
#define CURLINFO_SIZE_DOWNLOAD 16
#define CURLINFO_SPEED_DOWNLOAD 17
#define CURLINFO_SPEED_UPLOAD 18
#define CURLINFO_CONTENT_TYPE 19
#define CURLINFO_FTP_ENTRY_PATH 20
#define CURLINFO_REDIRECT_URL 21
#define CURLINFO_SSL_VERIFYRESULT 22
#define CURLINFO_PROXY_SSL_VERIFYRESULT 23
#define CURLINFO_PRIMARY_IP 24
#define CURLINFO_PRIMARY_PORT 25
#define CURLINFO_LOCAL_IP 26
#define CURLINFO_LOCAL_PORT 27
#define CURLINFO_HTTP_VERSION 28
#define CURLINFO_SCHEME 29
#define CURL_HTTP_VERSION_1_0 1
#define CURL_HTTP_VERSION_1_1 2
#define CURL_HTTP_VERSION_2_0 3

static int curl_easy_getinfo(CURL *curl, int info, void *param) {
    return CURLE_OK;
}

static int curl_strequal(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}