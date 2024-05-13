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

    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    std::string compile( unsigned int level = 0 ) const;

protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class CFactory: public ClassUnit
{
public:
    CFactory(const std::string& name):ClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class JavaFactory: public ClassUnit
{
public:
    JavaFactory(const std::string& name):ClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class CSharpFactory: public ClassUnit
{
public:
    CSharpFactory(const std::string& name):ClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};


#endif // CLASSUNIT_H
