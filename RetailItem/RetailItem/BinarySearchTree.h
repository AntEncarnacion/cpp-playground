//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "RetailItem.h"
#include "PrecondViolatedExcep.h"

typedef void(*FunctionType) (ItemType& anItem);

template<class ItemType>

class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
	BinaryNode<ItemType>* rootPtr;
	
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------
	// Recursively finds where the given node should be placed and
	// inserts it in a leaf at that point.
	BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
		BinaryNode<ItemType>* newNode);

	// Removes the given target value from the tree while maintaining a
	// binary search tree.
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
		const ItemType target,
		bool& success);

	// Removes a given node from a tree while maintaining a
	// binary search tree.
	BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

	// Removes the leftmost node in the left subtree of the node
	// pointed to by nodePtr.
	// Sets inorderSuccessor to the value in this node.
	// Returns a pointer to the revised subtree.
	BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
		ItemType& inorderSuccessor);

	// Returns a pointer to the node containing the given value,
	// or nullptr if not found.
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
		const ItemType& target) const;


	//void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	//void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	//void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;


public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinarySearchTree();
	BinarySearchTree(const ItemType& rootItem);
	BinarySearchTree(const BinarySearchTree<ItemType>& tree);
	virtual ~BinarySearchTree();

	//------------------------------------------------------------
	// Public Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;
	//int getHeight() const;
	//int getNumberOfNodes() const;
	ItemType getRootData() const;
	void setRootData(const ItemType& newData) const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const
		throw(NotFoundException);
	bool contains(const ItemType& anEntry) const;

	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;
	bool search(const ItemType& anEntry);
	void edit(const ItemType& anEntry);
	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide)
	{
		if (!isEmpty())
			clear();
		this = copyTree(&rightHandSide, rootPtr); // Call inherited method

		return *this;
	}  // end operator=


	BinarySearchTree<ItemType>& operator=(const RetailItem& rightHandSide)
	{
		if (!isEmpty())
			clear();

		else if (contains(rightHandSide))
			rightHandSide.getDescription();

		//this = copyTree(&rightHandSide, rootPtr); // Call inherited method

		return *this;
	}  // end operator=

}; // end BinarySearchTree

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,BinaryNode<ItemType>* newNodePtr) {
	if (subTreePtr == nullptr)
		return newNodePtr;
	else {
		/*string temp1 = subTreePtr->getItem().getDescription();
	     string temp2= newNodePtr->getItem().getDescription();*/

		if (subTreePtr->getItem() > newNodePtr->getItem())
		{
			subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr));
		}
		else {
			subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNodePtr));
		}
		return subTreePtr;
	}  // end else
}  // end insertInorder

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,const ItemType target,
	bool& success)
{
	if (subTreePtr == nullptr)
	{
		// Not found here
		success = false;
		return nullptr;
	}
	if (subTreePtr->getItem() == target)
	{
		// Item is in the root of some subtree
		subTreePtr = removeNode(subTreePtr);
		success = true;
		return subTreePtr;
	}
	else
	{
		if (subTreePtr->getItem() > target)
			// Search the left subtree
			subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
		else
			// Search the right subtree
			subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));

		return subTreePtr;
	}  // end if
}  // end removeValue

/** removes specfied child ponter. Improves modularity by removing duplicate code
 */
template<class ItemType>
BinaryNode<ItemType>* removeChildNode(BinaryNode<ItemType>* ChildNodePtr) {
	BinaryNode<ItemType>* nodeToConnectPtr = ChildNodePtr->getRightChildPtr();
	delete ChildNodePtr;
	ChildNodePtr = nullptr;
	return nodeToConnectPtr;
}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr) {
	if (nodePtr->isLeaf()) {
		delete nodePtr;
		return (nodePtr = nullptr); // Assign and return (perhaps student should have separate statements)
	}
	else if (nodePtr->getLeftChildPtr() == nullptr)  // Has rightChild only
	{
		//return removeChildNode(nodePtr->getRightChildPtr());
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
		delete nodePtr;
		nodePtr = nullptr;
		return nodeToConnectPtr; /**/
	}
	else if (nodePtr->getRightChildPtr() == nullptr) // Has left child only
	{
		//return removeChildNode(nodePtr->getLeftChildPtr());
		/* */BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
		delete nodePtr;
		nodePtr = nullptr;
		return nodeToConnectPtr;   /**/
	}
	else                                             // Has two children
	{
		// Traditional way to remove a value in a node with two children
		ItemType newNodeValue;
		nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
		nodePtr->setItem(newNodeValue);
		return nodePtr;

	
	}  // end if
}  // end removeNode

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
	ItemType& inorderSuccessor)
{
	if (nodePtr->getLeftChildPtr() == nullptr)
	{
		inorderSuccessor = nodePtr->getItem();
		return removeNode(nodePtr);
	}
	else
	{
		nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
		return nodePtr;
	}  // end if      
}  // end removeLeftmostNode


// Override findNode because now we can use a binary search:
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const
{
	if (subTreePtr == nullptr)
		return nullptr;                      // Not found 
	else if (subTreePtr->getItem() == target)
		return  subTreePtr;                //  Found 
	else if (subTreePtr->getItem() > target)       // Search left subtre
		return  findNode(subTreePtr->getLeftChildPtr(), target);
	else
		// Search right subtree 
		return  findNode(subTreePtr->getRightChildPtr(), target);
}  // end findNode



/*
template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}  // end if
}  // end inorder


template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
	}
}
*/

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr,rootPtr); // Call inherited method
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	this->destroyTree(rootPtr); // Call inherited method
}  // end destructor




//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}  // end isEmpty
/*
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return this->getHeightHelper(rootPtr); // Call inherited method
}  // end getHeight

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return this->getNumberOfNodesHelper(rootPtr); // Call inherited method
}  // end getNumberOfNodes
*/
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	this->destroyTree(rootPtr); // Call inherited method
	rootPtr = nullptr;
}  // end clear

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
	if (isEmpty())
		cout << "getRootData() called with empty tree." << endl;

	return rootPtr->getItem();
}  // end getRootData

// Must override setRootData to disable its affect:
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem) const  // throw(PrecondViolatedExcep)
{

	cout << "Cannot change root value in a BST!" << endl;
}  // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = insertInorder(rootPtr, newNodePtr);

	return true;
}  // end add

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, target, isSuccessful);
	return isSuccessful;
}  // end remove

// Override getEntry to use our improved findNode:
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)  // throw(NotFoundException)
{
	BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, anEntry);
	if (nodeWithEntry == nullptr) {
		cout << "Entry not found in tree." << endl;
		//throw NotFoundException("Entry not found in tree.");
	} // else
	return nodeWithEntry->getItem();
}  // end getEntry

// Override contains to use our improved findNode:
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
	//string temp1 = subTreePtr->getItem().getDescription();
	//string temp2= newNodePtr->getItem().getDescription();

	return findNode(rootPtr, anEntry);  // NULL is same as false
}  // end contains


//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	this->preorder(visit, rootPtr); // Call inherited method
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	this->inorder(visit, rootPtr); // Call inherited method
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	this->postorder(visit, rootPtr); // Call inherited method
}  // end postorderTraverse




//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////

/*template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
	if (!isEmpty())
		clear();
	this = copyTree(&rightHandSide,rootPtr); // Call inherited method

	return *this;
}  // end operator=
*/
template<class ItemType>
bool BinarySearchTree<ItemType>::search(const ItemType& newData)
{
	BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, newData);
	if (nodeWithEntry == nullptr)
		return false;
	else
		return true;
}
template<class ItemType>
void BinarySearchTree<ItemType>::edit(const ItemType& newEntry)
{
	BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, newEntry);
	nodeWithEntry->setItem(newEntry);

}
#endif

