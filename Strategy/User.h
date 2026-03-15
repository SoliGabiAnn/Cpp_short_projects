#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    std::string email;
    
public:
    User(const std::string& name, const std::string& email)
        : name(name), email(email) {}
    
    const std::string& getName() const { return name; }
    const std::string& getEmail() const { return email; }
};

#endif