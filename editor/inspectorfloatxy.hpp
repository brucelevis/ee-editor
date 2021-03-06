#ifndef EE_EDITOR_INSPECTOR_FLOAT_X_Y_HPP
#define EE_EDITOR_INSPECTOR_FLOAT_X_Y_HPP

#include "inspector.hpp"
#include "propertygetter.hpp"

#include <QWidget>

namespace Ui {
class InspectorFloatXY;
} // namespace Ui

namespace ee {
class InspectorFloatXY : public Inspector {
private:
    using Self = InspectorFloatXY;
    using Super = Inspector;

public:
    explicit InspectorFloatXY(QWidget* parent = nullptr);

    virtual ~InspectorFloatXY() override;

    Self* setPropertyName(const QString& x, const QString& y);
    Self* setPropertyDisplayName(const QString& name);
    Self* setSubPropertyDisplayName(const QString& x, const QString& y);
    Self* setSingleStep(float value);
    Self* setValuePrecision(int precision);
    Self* setMinimumValue(float value);
    Self* setMaximumValue(float value);

    virtual void refreshPropertyValue(const NodeGraph& graph,
                                      const SelectionTree& selection) override;

protected:
    void setPropertyValue(float x, float y);

private:
    Ui::InspectorFloatXY* ui_;
    std::unique_ptr<FloatPropertyGetter> propertyX_;
    std::unique_ptr<FloatPropertyGetter> propertyY_;
};
} // namespace ee

#endif // EE_EDITOR_INSPECTOR_FLOAT_X_Y_HPP
