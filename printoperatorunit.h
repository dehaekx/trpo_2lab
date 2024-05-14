#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "unit.h"

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const
    {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
protected:
    std::string m_text;
};


class CPrintOperator : public PrintOperatorUnit
{
public:
    explicit CPrintOperator( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0) const
    {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

class JavaPrintOperator : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0) const
    {
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

class CSharpPrintOperator : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperator( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0) const
    {
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORUNIT_H
