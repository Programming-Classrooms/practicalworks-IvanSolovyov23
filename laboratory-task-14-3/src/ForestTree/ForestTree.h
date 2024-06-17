#ifndef FOREST_TREE	
#define FOREST_TREE
#include "../Tree/Tree.h"


class ForestTree : public Tree {
private:
	size_t amountOfWood;
public:
	// Constructors and destructor
	ForestTree();
	ForestTree(std::string, size_t, allTypeOfTree, size_t);
	ForestTree(const ForestTree&);
	~ForestTree();

	// Getters
	size_t getAmountOfWood() const;

	// Setters
	void setAmountOfWood(const size_t);

	// Comparison operator
	bool operator==(const ForestTree&);

	// Assigment operator
	ForestTree& operator=(const ForestTree&);

	// Output operator
	friend std::ostream& operator<<(std::ostream&, const ForestTree&);

	// Method for output
	void print(std::ostream&) const override;
};
#endif // FOREST_TREE
