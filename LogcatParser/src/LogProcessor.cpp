#include "LogProcessor.h"
#include <fstream>
#include <stdexcept>

/*!
 * @brief Constructor of class
 */
LogProcessor::LogProcessor(const std::string &filePath) {
  processLogFile(filePath);
}

/*!
 * @brief Destructor of class.
 */
LogProcessor::~LogProcessor() = default;

// Open file and process data
/*!
 * @brief Process log file
 */
void LogProcessor::processLogFile(const std::string &filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open logcat file\n.");
  }

  std::string line;
  // Store the string after reading
  while (getline(file, line)) {
    // Insert a new "line" at end of into vector container
    parselogs_.emplace_back(line);
  }

  file.close();
}

/*!
 * @brief Returns filtered logs
 */
const std::vector<LogParser> &LogProcessor::getLogs() const {
  return parselogs_;
}
