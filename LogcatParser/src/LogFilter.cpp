#include "LogFilter.h"
#include <ctime>
#include <iomanip>
#include <sstream>

/*!
 * @brief Constructor of class
 */
LogFilter::LogFilter(int pid, int vid, const std::string &startTime,
                     const std::string &endTime)
    : pidFilter_(pid), vidFilter_(vid), startTimeFilter_(startTime),
      endTimeFilter_(endTime) {}

/*!
 * @brief Destructor of class.
 */
LogFilter::~LogFilter() = default;

/*!
 * @brief Filter the parsed loogs
 */
bool LogFilter::filterLog(const LogParser &entry) const {
  if (pidFilter_ != -1 && entry.getPid() != pidFilter_) {
    return false;
  }

  if (vidFilter_ != -1 && entry.getVid() != vidFilter_) {
    return false;
  }

  std::string entryTime = entry.getTimeString();
  if (startTimeFilter_ != "" && entryTime < startTimeFilter_) {
    return false;
  }

  if (endTimeFilter_ != "" && entryTime > endTimeFilter_) {
    return false;
  }

  return true;
}
