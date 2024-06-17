#include "ForestTree.h"


/*===========================================================================*/
/*============================ Constructors =================================*/
/*===========================================================================*/

ForestTree::ForestTree() : Tree(), amountOfWood(0) {}

ForestTree::ForestTree(std::string initNameTree, size_t initAgeTree, allTypeOfTree initTypeTree, size_t initAmountOfWood) :
	Tree(initNameTree, initAgeTree, initTypeTree), 
	amountOfWood(initAmountOfWood)
{}

ForestTree::ForestTree(const ForestTree& rhs) :
	Tree(rhs), 
	amountOfWood(rhs.amountOfWood)
{}

ForestTree::~ForestTree() {}




/*===========================================================================*/
/*=============================== Getters ===================================*/
/*===========================================================================*/

size_t ForestTree::getAmountOfWood() const {
	return this->amountOfWood;
}




/*===========================================================================*/
/*=============================== Setters ===================================*/
/*===========================================================================*/

void ForestTree::setAmountOfWood(const size_t initAmountOfWood) {
	this->amountOfWood = initAmountOfWood;
}




/*===========================================================================*/
/*======================== Assigment operator ==============================*/
/*===========================================================================*/

ForestTree& ForestTree::operator=(const ForestTree& rhs) {
	if (this != &rhs) {
		Tree::operator=(rhs);
		this->amountOfWood = rhs.amountOfWood;
	}
	return *this;
}




/*===========================================================================*/
/*========================= Comparison operator =============================*/
/*===========================================================================*/

bool ForestTree::operator==(const ForestTree& rhs) {
	Tree::operator==(rhs);
	return (amountOfWood == rhs.amountOfWood ? true : false);
}




/*===========================================================================*/
/*=========================== Output operator ===============================*/
/*===========================================================================*/

std::ostream& operator<<(std::ostream& out, const ForestTree& rhs) {
	out << "\nAmount of tree: " << rhs.amountOfWood;
	return out;
}




/*===========================================================================*/
/*========================== Method for output ==============================*/
/*===========================================================================*/

void ForestTree::print(std::ostream& out) const {
	Tree::print(out);
	out << *this;
}
