#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "abstactfactory.h"

// Клиентский код работает с фабриками и продуктами только через абстрактные
// типы: Абстрактная Фабрика и Абстрактный Продукт
std::string generateProgram(AbstactFactory & Fact) //Клиентский код
{
    //ClassUnit myClass( "MyClass" );
    auto myClass = Fact.CreateClass("MYCLASS");
    myClass->add(
        Fact.CreateMethod( "testFunction1", "void", 0),
        AbstractClassUnit::PUBLIC
        );
    myClass->add(
        Fact.CreateMethod( "testFunction2", "void", AbstractMethodUnit::STATIC ),
        AbstractClassUnit::PRIVATE
        );
    myClass->add(
        Fact.CreateMethod( "testFunction3", "int", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST ),
        AbstractClassUnit::PUBLIC
        );
    auto method = Fact.CreateMethod( "testFunction4", "void", AbstractMethodUnit::STATIC );
    method->add( Fact.CreatePrintOperator(R"(Hello, world!\n)"));
    myClass->add(method, AbstractClassUnit::PROTECTED );

    return myClass->compile();
}

int main()
{
    // std::cout << generateProgram() << std::endl;
    // cout << generateProgram() << std::endl;

    CPlusFactory CPlusFactory;
    JavaFactory JavaFactory;
    CSharpFactory CSharpFactory;

    std::cout << generateProgram(CPlusFactory) << std::endl;
    std::cout << generateProgram(JavaFactory) << std::endl;
    std::cout << generateProgram(CSharpFactory) << std::endl;
    return 0;
}
