#include "classunit.h"

AbstractClassUnit::AbstractClassUnit( const std::string& name ): m_name( name ) {}


void CPlusCLass::add( const std::shared_ptr< Unit >& unit, Flags flags )
{
    //assert(unit != NULL);

    if (unit)
    {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) // 3 модификатора доступа у с++
        {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }
    else
    {
        qDebug() << "UNIT IS NULLPTR!!!" << Qt::endl;
        return;
    }
}

std::string CPlusCLass::compile( unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) // 3 модификатора доступа
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] )
        {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

void JavaClass::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    //assert(unit != NULL);

    if (unit)
    {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() )
        {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }
    else
    {
        qDebug() << "UNIT IS NULLPTR!!!" << Qt::endl;
        return;
    }
}

std::string JavaClass::compile( unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] )
        {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}


void CSharpClass::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    //assert(unit != NULL);
    if (unit)
    {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() )
        {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
        }
    else
    {
        qDebug() << "UNIT IS NULLPTR!!!" << Qt::endl;
        return;
    }
}

std::string CSharpClass::compile( unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";

        for( const auto& f : m_fields[ i ] )
        {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
