#ifndef EMAILSERVICE_H
#define EMAILSERVICE_H

#include <iostream>
#include <string>
#include <memory>
#include "Logger.h"

class EmailService {
public:
    virtual ~EmailService() = default;
    virtual bool sendWelcomeEmail(const std::string& email) = 0;
};

class SmtpEmailService : public EmailService {
private:
    std::string smtpServer;
    int smtpPort;
    std::string senderEmail;
    std::shared_ptr<Logger> logger;
    
    bool validateEmail(const std::string& email) const {
        size_t atPos = email.find('@');
        size_t dotPos = email.find('.');
        return atPos != std::string::npos && dotPos != std::string::npos && atPos < dotPos;
    }
    
public:
    SmtpEmailService(std::shared_ptr<Logger> log,
                     const std::string& server = "smtp.gmail.com", 
                     int port = 587,
                     const std::string& sender = "noreply@coffee-shop.com")
        : smtpServer(server), smtpPort(port), senderEmail(sender), logger(log) {}
    
    bool sendWelcomeEmail(const std::string& email) override {
        if (!validateEmail(email)) {
            logger->log("[EMAIL ERROR] Invalid email format: " + email);
            return false;
        }
        
        logger->log("[EMAIL] Sending welcome email to: " + email);
        logger->log("[SMTP] Connecting to: " + smtpServer + ":" + std::to_string(smtpPort));
        logger->log("[SMTP] From: " + senderEmail);
        logger->log("[EMAIL] Welcome email sent successfully");
        
        return true;
    }
};

#endif