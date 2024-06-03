#ifndef CPLUSCLASS_H
#define CPLUSCLASS_H
#include "classunit.h"

class CPlusCLass: public AbstractClassUnit
{
public:
    const std::vector< std::string > ACCESS_MODIFIERS =
        { "public", "protected", "private"};
    CPlusCLass(const std::string& name):AbstractClassUnit(name)
    {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr< Unit >& unit, Flags flags) override;
    std::string compile( unsigned int level = 0, std::string access_modifiers = "" ) const override;
};

#endif // CPLUSCLASS_H
