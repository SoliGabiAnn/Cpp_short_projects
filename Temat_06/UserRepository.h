#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "User.h"

class UserRepository {
public:
    virtual ~UserRepository() = default;
    virtual bool save(const User& user) = 0;
};

#endif