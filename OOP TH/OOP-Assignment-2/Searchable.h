#ifndef SEARCHABLE_H
#define SEARCHABLE_H

#include <string>

class Searchable
{
public:
    Searchable();
    virtual bool matchesKeyword(const std::string &keyword) const = 0;
    virtual ~Searchable();
};

#endif
