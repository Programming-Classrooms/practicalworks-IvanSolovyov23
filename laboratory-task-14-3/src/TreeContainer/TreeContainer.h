#ifndef TREE_CONTAINER_H
#define TREE_CONTAINER_H
#include "../Tree/Tree.h"
#include <vector>


class TreeContainer : public Tree {
private:
	std::vector<Tree*> trees;
public:
	// Constructors and destructor
	TreeContainer();
	TreeContainer(std::string, size_t, allTypeOfTree, std::vector<Tree*>);
	TreeContainer(const TreeContainer&);
	~TreeContainer();

	// Methods for working with <trees>
	void printContainerOfTree() const;
	size_t countTreesOfCertainType(allTypeOfTree, std::string) const;
	void sortTrees();
	void addTree(Tree*);
};

#endif // TREE_CONTAINER_H
