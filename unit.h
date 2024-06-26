#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <vector>
#include <memory> // smart pointers - shared ptr
#include <QtGlobal>

class Unit
{
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add(const std::shared_ptr<Unit>&, Flags = 0)
    {
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile(unsigned int level = 0, std::string access_modifiers = "") const = 0;
protected:
    virtual std::string generateShift(unsigned int level) const;
};

#endif // UNIT_H
