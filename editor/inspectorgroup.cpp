#include "inspectorgroup.hpp"
#include "ui_inspectorgroup.h"

#include <QVBoxLayout>

namespace ee {
using Self = InspectorGroup;

Self::InspectorGroup(QWidget* parent)
    : Super(parent)
    , ui_(new Ui::InspectorGroup) {
    ui_->setupUi(this);
    connect(ui_->expandButton, &QPushButton::clicked, [this] {
        if (ui_->containerWidget->isHidden()) {
            ui_->containerWidget->setVisible(true);
        } else {
            ui_->containerWidget->setVisible(false);
        }
    });
}

Self::~InspectorGroup() {
    delete ui_;
}

void Self::setDisplayName(const QString& name) {
    ui_->expandButton->setText(name);
}

void Self::addInspector(Inspector* inspector) {
    Q_ASSERT(layout() != nullptr);
    ui_->containerWidget->layout()->addWidget(inspector);
    connect(inspector, &Inspector::propertyValueChanged,
            [this](const QString& propertyName, const cocos2d::Value& value) {
                Q_EMIT propertyValueChanged(propertyName, value);
            });
}

void Self::refreshPropertyValue(const NodeGraph& graph,
                                const SelectionTree& selection) {
    for (auto&& inspector : inspectors_) {
        inspector->refreshPropertyValue(graph, selection);
    }
}
} // namespace ee
