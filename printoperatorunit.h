#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "unit.h"

class AbstractPrintOperatorUnit : public Unit
{
public:
    explicit AbstractPrintOperatorUnit( const std::string& text ) : m_text( text ) { } // explicit запрещает неявное преобразование типов

protected:
    std::string m_text;
};


class CPlusPrintOperator : public AbstractPrintOperatorUnit
{
public:
    explicit CPlusPrintOperator( const std::string& text ) : AbstractPrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access_modifiers = "") const override
    {
        Q_UNUSED(access_modifiers);
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

class JavaPrintOperator : public AbstractPrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const std::string& text ) : AbstractPrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access_modifiers = "") const override
    {
        Q_UNUSED(access_modifiers);
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
};

class CSharpPrintOperator : public AbstractPrintOperatorUnit
{
public:
    explicit CSharpPrintOperator( const std::string& text ) : AbstractPrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access_modifiers = "") const override
    {
        Q_UNUSED(access_modifiers);
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORUNIT_H
