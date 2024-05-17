#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include "cassert"


class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        DEFAULT
    };
    const std::vector< std::string > ACCESS_MODIFIERS = { "public", "protected", "private" };
public:

    explicit ClassUnit( const std::string& name );

protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class CPlusCLass: public ClassUnit
{
public:
    CPlusCLass(const std::string& name):ClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class JavaClass: public ClassUnit
{
public:
    JavaClass(const std::string& name):ClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class CSharpClass: public ClassUnit
{
public:
    CSharpClass(const std::string& name):ClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};


#endif // CLASSUNIT_H
