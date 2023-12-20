#ifndef LOG_ANALYZER_H
#define LOG_ANALYZER_H

#include "LogProcessor.h"
#include "LogParser.h"
#include "LogFilter.h"
#include <string>
#include <vector>

class LogAnalyzer {
public:
  /*!
   * @brief Constructor of class LogAnalyzer
   */
  LogAnalyzer(const LogProcessor &LogProcessor);

  /*!
   * @brief Destructor of class LogAnalyzer.
   */
  ~LogAnalyzer();

  /*!
   * @brief Function to check command line entries valid or not
   */
  void applyFilter(const LogFilter &filter);

  /*!
   * @brief Function to display Filtered Logs
   */
  void displayFilteredLogs() const;

private:
  /*!
   * @brief LogParser instance
   */
  std::vector<LogParser> filteredLogs_;
};

#endif // LOG_ANALYZER_H
