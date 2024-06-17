#include "Tree.h"


/*===========================================================================*/
/*=========================== Constructors ==================================*/
/*===========================================================================*/

Tree::Tree() : nameTree("is unknown"), ageTree(17) {
	typeTree = allTypeOfTree::deciduous;
}

Tree::Tree(const Tree& rhs) : nameTree(rhs.nameTree), ageTree(rhs.ageTree), typeTree(rhs.typeTree)
{}

Tree::Tree(std::string initnameTree, size_t initageTree, allTypeOfTree inittypeTree): 
	nameTree(initnameTree), 
	ageTree(initageTree), 
	typeTree(inittypeTree)
{}

Tree::~Tree() {}




/*===========================================================================*/
/*=============================== Getters ===================================*/
/*===========================================================================*/

std::string Tree::getNameTree() const {
	return this->nameTree;
}

size_t Tree::getAgeTree() const {
	return this->ageTree;
}

allTypeOfTree Tree::getTypeTree() const {
	return this->typeTree;
}





/*===========================================================================*/
/*=============================== Setters ===================================*/
/*===========================================================================*/

void Tree::setNameTree(const std::string initNameTree) {
	this->nameTree = initNameTree;
}

void Tree::setAgeTree(const size_t initAgeTree) {
	this->ageTree = initAgeTree;
}

void Tree::setTypeTree(const allTypeOfTree initTypeTree) {
	this->typeTree = initTypeTree;
}




/*===========================================================================*/
/*========================== Assigment operator =============================*/
/*===========================================================================*/

Tree& Tree::operator=(const Tree& rhs) {
	if (this != &rhs) {
		nameTree = rhs.nameTree;
		ageTree = rhs.ageTree;
		typeTree = rhs.typeTree;
	}
	return *this;
}




/*===========================================================================*/
/*========================== Comparison operator ============================*/
/*===========================================================================*/

bool Tree::operator==(const Tree& rhs) {
	return (nameTree == rhs.nameTree ? true : false);
}




/*===========================================================================*/
/*=========================== Output operator ===============================*/
/*===========================================================================*/

std::ostream& operator<<(std::ostream& os, const allTypeOfTree& type)
{
	switch (type)
	{
	case allTypeOfTree::deciduous:
		os << "deciduous";
		break;
	case allTypeOfTree::coniferous:
		os << "coniferous";
		break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& out, const Tree& rhs) {
	out << "\nName of tree: " << rhs.nameTree;
	out << "\nAge of tree: " << rhs.ageTree;
	out << "\nType of tree: " << rhs.typeTree;
	return out;
}




/*===========================================================================*/
/*============================ Method for output ============================*/
/*===========================================================================*/

void Tree::print(std::ostream& out) const {
	out << *this;
}
