#include "TreeContainer.h"
#include <algorithm>


/*===========================================================================*/
/*============================ Constructors =================================*/
/*===========================================================================*/

TreeContainer::TreeContainer() : Tree(), trees(0) {}

TreeContainer::TreeContainer(std::string initNameTree, size_t initAgeTree, allTypeOfTree initTypeTree, std::vector<Tree*> initTrees) :
	Tree(initNameTree, initAgeTree, initTypeTree), 
	trees(initTrees)
{}

TreeContainer::TreeContainer(const TreeContainer& rhs):
	Tree(rhs), 
	trees(rhs.trees)
{}

TreeContainer::~TreeContainer() {}




/*===========================================================================*/
/*=================== Methods for working with <trees> ======================*/
/*===========================================================================*/

void TreeContainer::addTree(Tree* tree) {
    trees.push_back(tree);
}

void TreeContainer::printContainerOfTree() const {
    for (const auto& tree : trees) {
        tree->print(std::cout);
        std::cout << std::endl;
    }
}

size_t TreeContainer::countTreesOfCertainType(allTypeOfTree type, std::string name) const {
    size_t count = 0;
    for (const auto& tree : trees) {
        if (tree->getTypeTree() == type && tree->getNameTree() == name) {
            ++count;
        }
    }
    return count;
}

void TreeContainer::sortTrees() {
    std::sort(trees.begin(), trees.end(), [](Tree* tree1, Tree* tree2) {
        if (tree1->getNameTree() == tree2->getNameTree()) {
            return tree1->getAgeTree() > tree2->getAgeTree();
        }
        return tree1->getNameTree() < tree2->getNameTree();
        });
}