#ifndef EE_PARSER_PROPERTY_READER_HPP
#define EE_PARSER_PROPERTY_READER_HPP

#include <base/CCValue.h>

namespace ee {
class PropertyReader {
public:
    explicit PropertyReader(const cocos2d::ValueMap& properties);

    const cocos2d::ValueMap& getProperties() const;

    bool hasProperty(const std::string& name) const;

    /// Gets a generic property.
    /// @param name The property's name.
    cocos2d::Value getProperty(const std::string& name) const;

    /// Gets a generic property.
    /// @param name The property's name.
    /// @param defaultValue The default value of the property if it doesn't
    /// exist.
    cocos2d::Value getProperty(const std::string& name,
                               const cocos2d::Value& defaultValue) const;

    bool getBoolProperty(const std::string& name) const;
    bool getBoolProperty(const std::string& name, bool defaultValue) const;

    int getIntProperty(const std::string& name) const;
    int getIntProperty(const std::string& name, int defaultValue) const;

    float getFloatProperty(const std::string& name) const;
    float getFloatProperty(const std::string& name, float defaultValue) const;

    std::string getStringProperty(const std::string& name) const;
    std::string getStringProperty(const std::string& name,
                                  const std::string& defaultValue) const;

private:
    const cocos2d::ValueMap& properties_;
};
} // namespace ee

#endif // EE_PARSER_PROPERTY_READER_HPP
