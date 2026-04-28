#include <iostream>
#include <string>

#define DCHECK(condition) ((void)0)
#define DVLOG(level) std::cout

enum MediaStreamRequestResult {
};

struct UserMediaRequestInfo {
  int request;
};

class UserMediaClientImpl {
public:
  bool CalledOnValidThread();
  UserMediaRequestInfo* FindUserMediaRequestInfo(int request_id);
  void GetUserMediaRequestFailed(int request, MediaStreamRequestResult result, const std::string& message);
  void GetUserMediaRequestFailed(int* request, MediaStreamRequestResult result, const std::string& message);
  void DeleteUserMediaRequestInfo(UserMediaRequestInfo* request_info);
  void OnStreamGenerationFailed(int request_id, MediaStreamRequestResult result);
};