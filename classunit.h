#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include "cassert"
#include "QDebug"


class AbstractClassUnit : public Unit // абстрактный класс для наших классов с++ с# java
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE
    };
public:

    explicit AbstractClassUnit( const std::string& name );

protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};


// Конкретные продукты создаются соответствующими Конкретными Фабриками

class CPlusCLass: public AbstractClassUnit
{
public:
    const std::vector< std::string > ACCESS_MODIFIERS =
        { "public", "protected", "private"};
    CPlusCLass(const std::string& name):AbstractClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class JavaClass: public AbstractClassUnit
{
public:
    const std::vector< std::string > ACCESS_MODIFIERS =
        { "public", "protected", "private"};
    JavaClass(const std::string& name):AbstractClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};

class CSharpClass: public AbstractClassUnit
{
public:
    const std::vector< std::string > ACCESS_MODIFIERS =
        { "public", "protected", "private", "internal", "protected_internal", "private_protected", "file"};
    CSharpClass(const std::string& name):AbstractClassUnit(name){}
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0 ) const;
};


#endif // CLASSUNIT_H
