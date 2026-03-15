#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <string>
#include <memory>
#include "User.h"
#include "UserRepository.h"
#include "EmailService.h"
#include "Logger.h"

class UserManager {
private:
    std::shared_ptr<UserRepository> repository;
    std::shared_ptr<EmailService> emailService;
    std::shared_ptr<Logger> logger;
    
public:
    UserManager(
        std::shared_ptr<UserRepository> repo,
        std::shared_ptr<EmailService> email,
        std::shared_ptr<Logger> log
    ) : repository(repo), emailService(email), logger(log) {}
    
    bool createUser(const std::string& name, const std::string& email) {
        try {
            if (name.empty() || email.empty()) {
                logger->log("Failed to create user: invalid data");
                return false;
            }
            
            User user(name, email);
            
            if (!repository->save(user)) {
                logger->log("Failed to save user: " + name);
                return false;
            }
            
            if (!emailService->sendWelcomeEmail(email)) {
                logger->log("Failed to send welcome email to: " + email);
            }
            
            logger->log("User created successfully: " + name);
            return true;
            
        } catch (const std::exception& e) {
            logger->log("Exception during user creation: " + std::string(e.what()));
            return false;
        }
    }
};

#endif
