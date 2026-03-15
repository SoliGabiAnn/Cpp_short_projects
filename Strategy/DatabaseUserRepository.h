#ifndef DATABASEUSERREPOSITORY_H
#define DATABASEUSERREPOSITORY_H

#include <fstream>
#include <memory>
#include <sstream>
#include "User.h"
#include "UserRepository.h"
#include "Logger.h"

class DatabaseUserRepository : public UserRepository {
private:
    std::string dataFilePath = "users.json";
    std::shared_ptr<Logger> logger;
    
    std::string escapeJson(const std::string& str) const {
        std::string escaped;
        for (char c : str) {
            if (c == '"') escaped += "\\\"";
            else if (c == '\\') escaped += "\\\\";
            else if (c == '\n') escaped += "\\n";
            else if (c == '\r') escaped += "\\r";
            else escaped += c;
        }
        return escaped;
    }
    
public:
    DatabaseUserRepository(std::shared_ptr<Logger> log) : logger(log) {
        std::ifstream file(dataFilePath);
        if (!file.good()) {
            std::ofstream newFile(dataFilePath);
            if (newFile.is_open()) {
                newFile << "{\n  \"users\": []\n}\n";
                newFile.flush();
                newFile.close();
                logger->log("[REPO] JSON file created: " + dataFilePath);
            } else {
                logger->log("[REPO ERROR] Failed to create JSON file: " + dataFilePath);
            }
        } else {
            logger->log("[REPO] JSON file already exists: " + dataFilePath);
            file.close();
        }
    }
    
    bool save(const User& user) override {
        std::ifstream inFile(dataFilePath);
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        inFile.close();
        
        std::string content = buffer.str();
        size_t usersPos = content.find("\"users\": [");
        
        if (usersPos == std::string::npos) {
            logger->log("[REPO ERROR] Invalid JSON format in: " + dataFilePath);
            return false;
        }
        
        size_t insertPos = content.find('[', usersPos) + 1;
        
        std::ostringstream jsonEntry;
        jsonEntry << "\n    {\n"
                  << "      \"name\": \"" << escapeJson(user.getName()) << "\",\n"
                  << "      \"email\": \"" << escapeJson(user.getEmail()) << "\"\n"
                  << "    }";
        
        if (content[insertPos] != '\n' && content[insertPos] != ' ') {
            jsonEntry << ",";
        }
        
        content.insert(insertPos, jsonEntry.str());
        
        std::ofstream outFile(dataFilePath);
        if (!outFile.is_open()) {
            logger->log("[REPO ERROR] Cannot write to file: " + dataFilePath);
            return false;
        }
        
        outFile << content;
        outFile.close();
        
        logger->log("[REPO] User saved successfully: " + user.getName() + " (" + user.getEmail() + ")");
        return true;
    }
};

#endif
