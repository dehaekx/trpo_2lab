#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"
#include "cassert"
class AbstractMethodUnit : public Unit
{
public:
    enum Modifier // ???????????????
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };
public:
    AbstractMethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 )
    {
       // assert(unit != NULL); // check for no nullprt
        m_body.push_back( unit );
    }

protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class CPlusMethod: public AbstractMethodUnit
{
public:
    CPlusMethod( const std::string& name, const std::string& returnType, Flags flags ) :
        AbstractMethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0) const;
};

class JavaMethod: public AbstractMethodUnit
{
public:
    JavaMethod( const std::string& name, const std::string& returnType, Flags flags ) :
        AbstractMethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0) const;
};

class CSharpMethod: public AbstractMethodUnit
{
public:
    CSharpMethod( const std::string& name, const std::string& returnType, Flags flags ) :
        AbstractMethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0) const;
};

#endif // METHODUNIT_H
