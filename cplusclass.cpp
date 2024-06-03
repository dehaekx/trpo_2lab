#include "cplusclass.h"

void CPlusCLass::add( const std::shared_ptr< Unit >& unit, Flags flags ) // добавляет поле в класс с учетом его модификатора доступа
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

std::string CPlusCLass::compile( unsigned int level, std::string access_modifiers) const // генерирует код C++ для класса, включая его имя, поля и модификаторы доступа, рекурсивно вызывая `compile` для полей
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) // 3 модификатора доступа
    {
        if( m_fields[ i ].empty() ) // Проверяет, пуст ли вектор полей для данного модификатора доступа. Если пуст, пропускает этот модификатор
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) // перебор всех полей в векторе полей для данного модификатора доступа
        {
            result += f->compile( level + 1 ); // для каждого поля вызываем compile and save in result
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
