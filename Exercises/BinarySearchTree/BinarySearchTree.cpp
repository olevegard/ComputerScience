#include "BinarySearchTree.h"

const Comparable& BinarySearchTree::FindMin() const
{
	BinaryNode* current = root;
	BinaryNode* prev = root;

	while ( current )
	{
		prev = current;
		current = current->leftChild;
	}

	std::cout << "Min element is : " << prev->element << std::endl;
	return prev->element;
}
