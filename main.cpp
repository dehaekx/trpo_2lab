#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "abstactfacroty.h"

std::string generateProgram(AbstactFactory & fact)
{
    //ClassUnit myClass( "MyClass" );
    auto myClass = fact.CreateClass("MyClass");
    myClass->add(
        fact.CreateMethod( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass->add(
        fact.CreateMethod( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass->add(
        fact.CreateMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = fact.CreateMethod( "testFunc4", "void", MethodUnit::STATIC );

    method->add( fact.CreatePrintOperator(R"(Hello, world!\n)" ), 0);

    myClass->add(method, ClassUnit::PROTECTED );
    return myClass->compile();
}

int main() {
    // std::cout << generateProgram() << std::endl;
    // cout << generateProgram() << std::endl;

    CPlusFactory CPlusFactory;
    CSharpFactory CSharpFactory;
    JavaFactory JavaFactory;

    std::cout << generateProgram(CPlusFactory) << std::endl;
    std::cout << generateProgram(CSharpFactory) << std::endl;
    std::cout << generateProgram(JavaFactory) << std::endl;

    return 0;
}
