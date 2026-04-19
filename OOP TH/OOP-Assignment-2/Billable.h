#ifndef BILLABLE_H
#define BILLABLE_H

class Billable
{
public:
    Billable();
    virtual double finalAmount() const = 0;
    virtual ~Billable();
};

#endif
