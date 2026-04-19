#ifndef PERSONBASE_H
#define PERSONBASE_H

#include <string>

class PersonBase
{
protected:
    const int userID;
    std::string name;

public:
    PersonBase();
    PersonBase(int id, const std::string &n);

    virtual void viewProfile() const = 0;
    virtual void updateProfile() = 0;

    virtual ~PersonBase();
};

#endif
