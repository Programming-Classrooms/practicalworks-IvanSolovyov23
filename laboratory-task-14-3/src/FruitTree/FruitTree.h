#ifndef FRUITTREE_H
#define FRUITTREE_H
#include <iostream>
#include <ctime>
#include "../Tree/Tree.h"


class FruitTree : public Tree {
private:
	size_t massOfHarvest;
	size_t averageStorageTime;
public:
	// Constructors and destructor
	FruitTree();
	FruitTree(std::string, size_t, allTypeOfTree, size_t, size_t);
	FruitTree(const FruitTree&);
	~FruitTree();

	// Getters
	size_t getMassOfHarvest() const;
	size_t getAvergeStorageTime() const;

	// Setters
	void setMassOfHarvest(const size_t);
	void setAverageStorageTime(const size_t);

	// Assignment operator
	FruitTree& operator=(const FruitTree&);

	// Output operator
	friend std::ostream& operator<<(std::ostream&, const FruitTree&);

	// Method for output
	void print(std::ostream&) const override;

};

#endif // FRUITTREE_H
