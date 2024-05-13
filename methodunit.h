#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"
#include "cassert"
class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 )
    {
        assert(unit != NULL); // check for no nullprt
        m_body.push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level );
        if( m_flags & STATIC )
        {
            result += "static ";
        }
        else if( m_flags & VIRTUAL )
        {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";

        if( m_flags & CONST )
        {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body )
        {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class CMethod: public MethodUnit
{
    CMethod( const std::string& name, const std::string& returnType, Flags flags ) :
        MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0) const;
};

class JavaMethod: public MethodUnit
{
    JavaMethod( const std::string& name, const std::string& returnType, Flags flags ) :
        MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0) const;
};

class CSharpMethod: public MethodUnit
{
    CSharpMethod( const std::string& name, const std::string& returnType, Flags flags ) :
        MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0) const;
};

#endif // METHODUNIT_H
