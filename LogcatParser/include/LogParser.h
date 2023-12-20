#ifndef LOG_PARSER_H
#define LOG_PARSER_H

#include <string>

class LogParser {
public:
  /*!
   * @brief Constructor of class LogParser
   */
  LogParser() = default;

  /*!
   * @brief Parametrised constructor
   */
  LogParser(const std::string &log);

  /*!
   * @brief Destructor of class LogParser.
   */
  ~LogParser();

  /*!
   * @brief Returns date
   */
  const std::string &getDate() const;

  /*!
   * @brief Returns time
   */
  const std::string &getTimeString() const;

  /*!
   * @brief Returns pid
   */
  int getPid() const;

  /*!
   * @brief
   */
  int getVid() const;

  /*!
   * @brief Returns log leve;
   */
  const std::string &getLogLevel() const;

  /*!
   * @brief Returns tag
   */
  const std::string &getTag() const;

  /*!
   * @brief Returns msg
   */
  const std::string &getMessage() const;

private:
  /*!
   * @brief Decalartions of filters
   */
  int pid_;
  int vid_;
  std::string date_;
  std::string time_;
  std::string logLevel_;
  std::string tag_;
  std::string message_;

  /*!
   * @brief Parse the logs
   */
  void parseLog(const std::string &log);
};

#endif // LOG_PARSER_H
