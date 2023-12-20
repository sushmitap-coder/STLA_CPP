#ifndef LOG_FILTER_H
#define LOG_FILTER_H

#include "LogParser.h"
#include <string>
#include <vector>

class LogFilter {
public:
  /*!
   * @brief Constructor of class LogFilter
   */
  LogFilter(int pid, int vid, const std::string &startTime,
            const std::string &endTime);

  /*!
   * @brief Destructor of class LogFilter.
   */
  ~LogFilter();

  /*!
   * @brief Filter the parsed loogs
   */
  bool filterLog(const LogParser &entry) const;

private:
/*!
   * @brief Decalaration of pid, vid, start and end time filters
   */
  int pidFilter_;
  int vidFilter_;
  std::string startTimeFilter_;
  std::string endTimeFilter_;
};

#endif // LOG_FILTER_H
