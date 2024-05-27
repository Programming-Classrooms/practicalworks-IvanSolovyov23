#include "FruitTree.h"


/*===========================================================================*/
/*=========================== Constructors ==================================*/
/*===========================================================================*/

FruitTree::FruitTree() : Tree(), massOfHarvest(0), averageStorageTime(0) {}

FruitTree::FruitTree(std::string initNameTree, size_t initAgeTree, allTypeOfTree initTypeTree, size_t initmassOfHarvest, size_t initAverageSrtorageTime) :
	Tree(initNameTree, initAgeTree, initTypeTree), 
	massOfHarvest(initmassOfHarvest), 
	averageStorageTime(initAverageSrtorageTime)
{}

FruitTree::FruitTree(const FruitTree& rhs) : 
	Tree(rhs), 
	massOfHarvest(rhs.massOfHarvest), 
	averageStorageTime(rhs.averageStorageTime)
{}

FruitTree::~FruitTree() {}




/*===========================================================================*/
/*=============================== Getters ===================================*/
/*===========================================================================*/

size_t FruitTree::getMassOfHarvest() const {
	return this->massOfHarvest;
}

size_t FruitTree::getAvergeStorageTime() const {
	return this->averageStorageTime;
}




/*===========================================================================*/
/*=============================== Setters ===================================*/
/*===========================================================================*/

void FruitTree::setMassOfHarvest(const size_t initMassOfHarvest) {
	this->massOfHarvest = initMassOfHarvest;
}

void FruitTree::setAverageStorageTime(const size_t initAvrageStorageTime) {
	this->averageStorageTime = initAvrageStorageTime;
}




/*===========================================================================*/
/*====================== Assignment operator ================================*/
/*===========================================================================*/

FruitTree& FruitTree::operator=(const FruitTree& rhs) {
	if (this != &rhs) {
		Tree::operator=(rhs);
		massOfHarvest = rhs.massOfHarvest;
		averageStorageTime = rhs.averageStorageTime;
	}
	return *this;
}




/*===========================================================================*/
/*=========================== Output operator ===============================*/
/*===========================================================================*/

std::ostream& operator<<(std::ostream& out, const FruitTree& rhs) {
	/*out << *((Tree*)&rhs);*/
	out << "\nMass of Harvest this tree: " << rhs.massOfHarvest;
	out << "\nAverage storage time of this tree(day): " << rhs.averageStorageTime;
	return out;
}




/*===========================================================================*/
/*=========================== Method for output =============================*/
/*===========================================================================*/

void FruitTree::print(std::ostream& out) const {
	Tree::print(out);
	out << *this;
}
