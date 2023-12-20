#include "LogAnalyzer.h"
#include <iostream>

/*!
 * @brief Constructor of class LogAnalyzer
 */
LogAnalyzer::LogAnalyzer(const LogProcessor &LogProcessor) {
  filteredLogs_ = LogProcessor.getLogs();
}

/*!
 * @brief Destructor of class.
 */
LogAnalyzer::~LogAnalyzer() = default;

/*!
 * @brief Function to check command line entries valid or not
 */
void LogAnalyzer::applyFilter(const LogFilter &filter) {
  std::vector<LogParser> tempLogs;
  for (const auto &ref_element : filteredLogs_) {
    if (filter.filterLog(ref_element)) {
      tempLogs.push_back(ref_element);
    }
  }
  filteredLogs_ = tempLogs;
}

/*!
 * @brief Function to display Filtered Logs
 */
void LogAnalyzer::displayFilteredLogs() const {
  std::cout << "Filtered Logs:\n";
  for (const auto &ref_element : filteredLogs_) {
    std::cout << ref_element.getDate() << " " << ref_element.getTimeString() << " "
              << ref_element.getPid() << " " << ref_element.getVid() << " "
              << ref_element.getLogLevel() << " " << ref_element.getTag() << ": "
              << ref_element.getMessage() << std::endl;
  }
}
