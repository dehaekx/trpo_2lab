#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include "cassert"
#include "QDebug"

class AbstractClassUnit : public Unit // первый абстрактный продукт для наших классов с++ с# java
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

    explicit AbstractClassUnit( const std::string& name ); // Ключевое слово explicit запрещает неявное преобразование типов
protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >; // поля класса
    std::vector< Fields > m_fields; // поля класса, сгруппированные по модификаторам доступа
};

#endif // CLASSUNIT_H
