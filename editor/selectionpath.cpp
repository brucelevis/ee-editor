#include "selectionpath.hpp"

#include <parser/nodegraph.hpp>

#include <2d/CCNode.h>

namespace ee {
using Self = SelectionPath;

Self Self::emptySelection() {
    return Self(false, {});
}

Self Self::selectRoot() {
    return Self(true, {});
}

Self Self::select(const QVector<int>& indices) {
    return Self(false, indices);
}

Self Self::fromIndex(const QModelIndex& index, const QModelIndex& ancestor) {
    if (index == ancestor) {
        return selectRoot();
    }
    QVector<int> indices;
    auto currentIndex = index;
    while (currentIndex != ancestor) {
        indices.append(currentIndex.row());
        currentIndex = currentIndex.parent();
    }
    std::reverse(indices.begin(), indices.end());
    return select(indices);
}

Self::SelectionPath(bool root, const QVector<int>& indices)
    : root_(root)
    , indices_(indices) {}

bool Self::isEmpty() const {
    return not isRoot() && getIndices().isEmpty();
}

bool Self::isRoot() const {
    return root_;
}

const QVector<int>& Self::getIndices() const {
    return indices_;
}

bool Self::isSibling(const Self& other) const {
    if (isRoot()) {
        return other.isRoot();
    }
    if (indices_.size() != other.indices_.size()) {
        return false;
    }
    for (int i = 0; i + 1 < indices_.size(); ++i) {
        if (indices_.at(i) != other.indices_.at(i)) {
            return false;
        }
    }
    return true;
}

cocos2d::Node* Self::find(cocos2d::Node* node) const {
    Q_ASSERT(not isEmpty());
    auto ptr = node;
    for (auto&& index : indices_) {
        ptr = ptr->getChildren().at(index);
    }
    return ptr;
}

const cocos2d::Node* Self::find(const cocos2d::Node* node) const {
    return static_cast<const cocos2d::Node*>(
        find(const_cast<cocos2d::Node*>(node)));
}

NodeGraph& Self::find(NodeGraph& graph) const {
    Q_ASSERT(not isEmpty());
    auto ptr = &graph;
    for (auto&& index : indices_) {
        ptr = &ptr->getChild(static_cast<std::size_t>(index));
    }
    return *ptr;
}

const NodeGraph& Self::find(const NodeGraph& graph) const {
    return static_cast<const NodeGraph&>(find(const_cast<NodeGraph&>(graph)));
}
} // namespace ee
