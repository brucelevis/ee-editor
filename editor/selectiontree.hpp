#ifndef EE_EDITOR_SELECTION_TREE_HPP
#define EE_EDITOR_SELECTION_TREE_HPP

#include <vector>

namespace ee {
class SelectionPath;

class SelectionTree {
private:
    using Self = SelectionTree;

public:
    static Self emptySelection();
    static Self select(const SelectionPath& path);
    static Self select(const std::vector<SelectionPath>& paths);

    bool isEmpty() const;
    std::size_t getSize() const;

    const std::vector<SelectionPath>& getPaths() const;

    Self& addPath(const SelectionPath& path);

protected:
    explicit SelectionTree(const std::vector<SelectionPath>& paths);

private:
    std::vector<SelectionPath> paths_;
};
} // namespace ee

#endif // EE_EDITOR_SELECTION_TREE_HPP
