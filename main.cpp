#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "abstactfactory.h"


std::string generateProgram(AbstactFactory & Fact) //Клиентский код
{
    //ClassUnit myClass( "MyClass" );
    auto myClass = Fact.CreateClass("MyClass");
    myClass->add(
        Fact.CreateMethod( "testFunc1", "void", 0 ),
        AbstractClassUnit::PUBLIC
        );
    myClass->add(
        Fact.CreateMethod( "testFunc2", "void", AbstractMethodUnit::STATIC ),
        AbstractClassUnit::PRIVATE
        );
    myClass->add(
        Fact.CreateMethod( "testFunc3", "void", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST ),
        AbstractClassUnit::PUBLIC
        );
    auto method = Fact.CreateMethod( "testFunc4", "void", AbstractMethodUnit::STATIC );

    method->add( Fact.CreatePrintOperator(R"(Hello, world!\n)"));
    myClass->add(method, AbstractClassUnit::PROTECTED );

    return myClass->compile();
}

int main(int argc, char *argv[]) {
    // std::cout << generateProgram() << std::endl;
    // cout << generateProgram() << std::endl;

    CPlusFactory CPlusFactory;
    // CSharpFactory CSharpFactory;
    // JavaFactory JavaFactory;
    QCoreApplication a(argc, argv);
    std::cout << generateProgram(CPlusFactory) << std::endl;
    // std::cout << generateProgram(CSharpFactory) << std::endl;
    // std::cout << generateProgram(JavaFactory) << std::endl;

    return a.exec();
}
