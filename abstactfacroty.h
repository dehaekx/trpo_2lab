#ifndef ABSTACTFACROTY_H
#define ABSTACTFACROTY_H
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include <memory>

class AbstactFactory
{
public:
    virtual ~AbstactFactory() = default;
    virtual std::shared_ptr<Unit> CreateClass(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    virtual std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) = 0;
};

class CPlusFactory: public AbstactFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) // возвращаем интерйесы
    {
        return std::make_shared<CPlusCLass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        return std::make_shared<CPlusMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text)
    {
        return std::make_shared<CPlusPrintOperator>(text);
    }
};

class JavaFactory: public AbstactFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name)
    {
        return std::make_shared<JavaClass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        return std::make_shared<JavaMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text)
    {
        return std::make_shared<JavaPrintOperator>(text);
    }
};

class CSharpFactory: public AbstactFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name)
    {
        return std::make_shared<CSharpClass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags)
    {
        return std::make_shared<CSharpMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text)
    {
        return std::make_shared<CSharpPrintOperator>(text);
    }
};

#endif // ABSTACTFACROTY_H
