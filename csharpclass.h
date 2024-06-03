#ifndef CSHARPCLASS_H
#define CSHARPCLASS_H
#include "classunit.h"

class CSharpClass: public AbstractClassUnit
{
public:
    const std::vector< std::string > ACCESS_MODIFIERS =
        { "public", "protected", "private", "internal", "protected_internal", "private_protected", "file"};
    CSharpClass(const std::string& name):AbstractClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr< Unit >& unit, Flags flags) override;
    std::string compile( unsigned int level = 0, std::string access_modifiers = "") const override;
};

#endif // CSHARPCLASS_H
