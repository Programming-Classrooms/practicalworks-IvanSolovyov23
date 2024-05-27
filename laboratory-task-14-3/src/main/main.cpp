#include <iostream>
#include "../Tree/Tree.h"
#include "../ForestTree/ForestTree.h"
#include "../FruitTree/FruitTree.h"
#include "../TreeContainer/TreeContainer.h"


int main() 
{
    TreeContainer container;
    container.addTree(new FruitTree("Cherry", 5, allTypeOfTree::deciduous, 50, 31));
    container.addTree(new ForestTree("Birch", 17, allTypeOfTree::deciduous, 232));
    container.addTree(new ForestTree("Fir", 40, allTypeOfTree::coniferous, 20));

    container.printContainerOfTree();
    
    container.sortTrees();
    std::cout << "\n\nTrees after sorting:\n\n";
    container.printContainerOfTree();

	return 0;
}
