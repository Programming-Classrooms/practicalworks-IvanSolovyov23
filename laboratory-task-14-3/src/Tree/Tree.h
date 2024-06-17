#ifndef TREE_H
#define TREE_H
#include <iostream>


enum class allTypeOfTree { deciduous, coniferous };

class Tree {
private:
	std::string nameTree;
	size_t ageTree;
	allTypeOfTree typeTree;
public:
	// Constructors and destructor
	Tree();
	Tree(std::string, size_t, allTypeOfTree);
	Tree(const Tree&);
	virtual ~Tree();

	// Getters 
	std::string getNameTree() const;
	size_t getAgeTree() const;
	allTypeOfTree getTypeTree() const;

	// Setters
	void setNameTree(const std::string);
	void setAgeTree(const size_t);
	void setTypeTree(const allTypeOfTree);

	// Comparison operator
	bool operator==(const Tree&);

	// Assigment operator
	Tree& operator=(const Tree&);

	// Output operator
	friend std::ostream& operator<<(std::ostream&, const Tree&);

	// Method for output
	virtual void print(std::ostream&) const;

};

#endif // TREE_H

