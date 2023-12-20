#ifndef LOG_PROCESSOR_H
#define LOG_PROCESSOR_H

#include "LogParser.h"
#include <string>
#include <vector>

class LogProcessor {
public:
  /*!
   * @brief constructor of class LogProcessor.
   */
  LogProcessor(const std::string &filePath);

  /*!
   * @brief Destructor of class LogProcessor.
   */
  ~LogProcessor();

  /*!
   * @brief Instance of LogParser
   */
  const std::vector<LogParser> &getLogs() const;

private:
/*!
   * @brief Instance of logParser class
   */
  std::vector<LogParser> parselogs_;

  /*!
   * @brief Process log file
   */
  void processLogFile(const std::string &filePath);
};

#endif // LOG_PROCESSOR_H
