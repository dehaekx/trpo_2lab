#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <vector>
#include <memory> // smart pointers - shared ptr
using namespace std;

class Unit
{
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add(const std::shared_ptr<Unit>&, Flags)
    {
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    virtual std::string generateShift(unsigned int level) const;
};

#endif // UNIT_H
