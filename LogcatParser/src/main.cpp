#include "LogAnalyzer.h"
#include "LogProcessor.h"
#include "LogFilter.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int pid_argv = -1;
  int vid_argv = -1;
  std::string startTime_argv = "";
  std::string endTime_argv = "";

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <logcat_file_path> [options]\n";
    return 1;
  }
  std::cout << "Total number of arguments entered on command line: " << argc
            << std::endl;

  // Store filepath to string
  std::string FilePath = argv[1];

  // Parse command-line options for filtering
  for (int i = 2; i < argc; i++) {
    std::string option = argv[i];
    if (option == "--pid") {
      if (i + 1 < argc) {
        pid_argv = std::stoi(argv[++i]);
      }
    } else if (option == "--vid") {
      if (i + 1 < argc) {
        vid_argv = std::stoi(argv[++i]);
      }
    } else if (option == "--start") {
      if (i + 1 < argc) {
        startTime_argv = argv[++i];
      }
    } else if (option == "--end") {
      if (i + 1 < argc) {
        endTime_argv = argv[++i];
      }
    } else {
      std::cerr << "Invalid option: " << option << "\n";
      return 1;
    }
  }

  try {
    // create LogProcessor instance
    LogProcessor logProcessor(FilePath);

    // create loganalyze instance
    LogAnalyzer logAnalyzer(logProcessor);

    // create LogFilter instance
    LogFilter logFilter(pid_argv, vid_argv, startTime_argv, endTime_argv);

    // check command line entries valid or not
    logAnalyzer.applyFilter(logFilter);

    logAnalyzer.displayFilteredLogs();
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}
