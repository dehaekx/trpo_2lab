#ifndef ABSTACTFACTORY_H
#define ABSTACTFACTORY_H

#include "cplusclass.h"
#include "javaclass.h"
#include "csharpclass.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "unit.h"
#include <memory>

class AbstactFactory // Абстрактная фабрика объявляет методы создания различных абстрактных продуктов (CreateClass, CreateMethod, CreatePrintOperator)
{
public:
    virtual ~AbstactFactory() = default;
    virtual std::shared_ptr<Unit> CreateClass(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    virtual std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) = 0;
};

// Конкретные фабрики реализуют методы абстрактной фабрики, позволяя создавать все продукты определённой вариации
class CPlusFactory: public AbstactFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name)override // возвращаем продукты
    {
        return std::make_shared<CPlusCLass>(name); // возвращает умный указатель на объект Unit
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)override
    {
        return std::make_shared<CPlusMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text)override
    {
        return std::make_shared<CPlusPrintOperator>(text);
    }
};

class JavaFactory: public AbstactFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name)override
    {
        return std::make_shared<JavaClass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)override
    {
        return std::make_shared<JavaMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text)override
    {
        return std::make_shared<JavaPrintOperator>(text);
    }
};

class CSharpFactory: public AbstactFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name)override
    {
        return std::make_shared<CSharpClass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)override
    {
        return std::make_shared<CSharpMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text)override
    {
        return std::make_shared<CSharpPrintOperator>(text);
    }
};

#endif // ABSTACTFACTORY_H
