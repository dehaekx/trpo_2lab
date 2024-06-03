#include "javaclass.h"

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

std::string JavaClass::compile( unsigned int level, std::string access_modifiers) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }

        for( const auto& f : m_fields[ i ] )
        {
            access_modifiers = ACCESS_MODIFIERS[i];
            result += f->compile( level, access_modifiers );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
