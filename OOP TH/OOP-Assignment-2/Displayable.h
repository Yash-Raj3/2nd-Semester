#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

class Displayable
{
public:
    Displayable();
    virtual void displayDetails() const = 0;
    virtual ~Displayable();
};

#endif
