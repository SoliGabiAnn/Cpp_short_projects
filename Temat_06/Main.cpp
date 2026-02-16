#include <iostream>
#include <memory>
#include "UserManager.h"
#include "DatabaseUserRepository.h"
#include "EmailService.h"
#include "Logger.h"

int main() {
    // Initialize logger
    auto logger = std::make_shared<FileLogger>("app.log");
    logger->log("[APP] Application started");
    
    // Initialize repository (JSON file-based storage)
    auto repository = std::make_shared<DatabaseUserRepository>(logger);
    
    // Initialize email service with SmtpEmailService (concrete implementation)
    auto emailService = std::make_shared<SmtpEmailService>(logger);
    
    // Initialize user manager
    UserManager userManager(repository, emailService, logger);
    
    // Create users
    std::cout << "=== User Management System ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Creating user 1..." << std::endl;
    userManager.createUser("John Doe", "john.doe@example.com");
    std::cout << std::endl;
    
    std::cout << "Creating user 2..." << std::endl;
    userManager.createUser("Jane Smith", "jane.smith@example.com");
    std::cout << std::endl;
    
    std::cout << "Creating user 3..." << std::endl;
    userManager.createUser("Bob Johnson", "bob.johnson@example.com");
    std::cout << std::endl;
    
    // Test invalid user
    std::cout << "Creating invalid user (empty name)..." << std::endl;
    userManager.createUser("", "invalid@example.com");
    std::cout << std::endl;
    
    logger->log("[APP] Application completed");
    std::cout << "Application finished. Check app.log and users.json for details." << std::endl;
    
    return 0;
}
