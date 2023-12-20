#include "LogParser.h"
#include <iomanip>
#include <sstream>

/*!
 * @brief Constructor of class
 */
LogParser::LogParser(const std::string &log) {
  // parse processed log
  parseLog(log);
}

/*!
 * @brief Destructor of class.
 */
LogParser::~LogParser() = default;

/*!
 * @brief Parse the logs
 */
void LogParser::parseLog(const std::string &log) {
  // read formatted data from strings
  std::istringstream iss(log);
  iss >> date_ >> time_ >> pid_ >> vid_ >> logLevel_;
  std::string tagAndMessage;
  std::getline(iss >> std::ws, tagAndMessage);

  // find the position of colon (:)
  size_t pos = tagAndMessage.find(":");
  if (pos != std::string::npos) {
    // save substring before the colon
    tag_ = tagAndMessage.substr(0, pos);
    // save substring after the colon
    message_ = tagAndMessage.substr(pos + 1);
  }
}

/*!
 * @brief Returns date
 */
const std::string &LogParser::getDate() const { return date_; }

/*!
 * @brief Returns time
 */
const std::string &LogParser::getTimeString() const { return time_; }

/*!
 * @brief Returns pid
 */
int LogParser::getPid() const { return pid_; }

/*!
 * @brief Returns vid
 */
int LogParser::getVid() const { return vid_; }

/*!
 * @brief Returns log level
 */
const std::string &LogParser::getLogLevel() const { return logLevel_; }

/*!
 * @brief Returns tag
 */
const std::string &LogParser::getTag() const { return tag_; }

/*!
 * @brief Returns msg
 */
const std::string &LogParser::getMessage() const { return message_; }
