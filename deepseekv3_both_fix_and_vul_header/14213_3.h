#include <memory>
#include <string>
#include <cstdlib>
#include <iostream>

enum LogLevel {
  FATAL,
  WARN
};

enum LogTopic {
  STARTUP,
  AUTHENTICATION
};

class Logger {
public:
  static constexpr LogTopic STARTUP = ::STARTUP;
  static constexpr LogTopic AUTHENTICATION = ::AUTHENTICATION;
};

class ProgramOptions {
public:
  class ProcessingResult {
  public:
    bool touched(const std::string&);
  };
  ProcessingResult processingResult();
};

struct Result {
  bool fail();
  std::string errorMessage();
};

#define LOG_TOPIC(id, level, topic) std::cout
#define FATAL_ERROR_EXIT() std::exit(1)

namespace arangodb {
class Logger : public ::Logger {};
}

class AuthenticationFeature {
private:
  std::string _jwtSecretKeyfileProgramOption;
  std::string _jwtSecretFolderProgramOption;
  std::string _jwtSecretProgramOption;
  size_t _maxSecretLength;
  double _sessionTimeout;

  Result loadJwtSecretsFromFile();
public:
  void validateOptions(std::shared_ptr<ProgramOptions> options);
};