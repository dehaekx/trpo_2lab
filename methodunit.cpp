#include "methodunit.h"

std::string CPlusMethod::compile(unsigned int level) const
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

std::string JavaMethod::compile(unsigned int level) const // добавить нормальную реализацию
{
    std::string result = generateShift( level );
    if( m_flags & STATIC && m_flags & FINAL )
    {
        result += "static final";
    }
    else if( m_flags & STATIC )
    {
        result += "static";
    }
    else if (m_flags & FINAL)
    {
        result += "final";
    }
    else if (m_flags & ABSTRACT)
    {
        result += "abstract";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) // джава не поддерживает const methods
    {
        result += "";
    }
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

std::string CSharpMethod::compile(unsigned int level) const // сделать нормальную реализацию
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
    if( m_flags & CONST ) // с# не поддерживает const methods
    {
        result += "";
    }
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}
