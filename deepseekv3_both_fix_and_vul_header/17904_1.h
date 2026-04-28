#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void CURL;
typedef int CURLcode;

int Curl_isunreserved(unsigned char in);
CURLcode Curl_convert_to_network(CURL *handle, unsigned char *in, int length);