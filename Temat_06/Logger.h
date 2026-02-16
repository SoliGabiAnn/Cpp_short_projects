#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& message) = 0;
};

class FileLogger : public Logger {
private:
    std::string logFilePath;
    
    std::string getCurrentTime() const {
        auto now = std::time(nullptr);
        auto tm = *std::localtime(&now);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
    
    void createLogFileIfNotExists() const {
        // ifstream = INPUT - check if file exists
        std::ifstream file(logFilePath);
        if (!file.good()) {
            // ofstream = OUTPUT - create/write to file
            std::ofstream newFile(logFilePath);
            if (newFile.is_open()) {
                newFile << "=== Log File Created ===" << std::endl;
                newFile.close();
            }
        }
        file.close();
    }
    
public:
    explicit FileLogger(const std::string& path = "app.log")
        : logFilePath(path) {
        createLogFileIfNotExists();
    }
    
    void log(const std::string& message) override {
        std::string timestamp = "[" + getCurrentTime() + "] ";
        std::string fullMessage = timestamp + message;
        
        // Write to console
        std::cout << fullMessage << std::endl;
        
        // ofstream = OUTPUT - append to existing file
        std::ofstream logFile(logFilePath, std::ios::app);
        if (logFile.is_open()) {
            logFile << fullMessage << std::endl;
            logFile.flush();
            logFile.close();
        } else {
            std::cerr << "ERROR: Could not open log file: " << logFilePath << std::endl;
        }
    }
};
#endif