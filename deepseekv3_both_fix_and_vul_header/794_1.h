#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <shadow.h>
#include <errno.h>
#include <crypt.h>

#ifdef _WIN32
#include <windows.h>
#include <winbase.h>
#endif

#define PCAP_ERRBUF_SIZE 256