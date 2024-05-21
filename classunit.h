#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include "cassert"
#include "QDebug"

class AbstractClassUnit : public Unit // абстрактный продукт для наших классов с++ с# java
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
    CPlusCLass(const std::string& name):AbstractClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0, std::string access_modifiers = "" ) const;
};

class JavaClass: public AbstractClassUnit
{
public:
    const std::vector< std::string > ACCESS_MODIFIERS =
        { "public", "protected", "private"};
    JavaClass(const std::string& name):AbstractClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0, std::string access_modifiers = "")const;
};

class CSharpClass: public AbstractClassUnit
{
public:
    const std::vector< std::string > ACCESS_MODIFIERS =
        { "public", "protected", "private", "internal", "protected_internal", "private_protected", "file"};
    CSharpClass(const std::string& name):AbstractClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile( unsigned int level = 0, std::string access_modifiers = "") const;
};


#endif // CLASSUNIT_H
