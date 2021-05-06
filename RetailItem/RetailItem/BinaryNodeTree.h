#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"
#include "BinaryNode.h" // contains definitions for TreeNode
#include <iostream>                      
#include <cassert>
#include "RetailItem.h"

#ifndef BINARYNODETREE_H
#define BINARYNODETREE_H


typedef void(*FunctionType) (ItemType& anItem);

template<class ItemType>
class BinaryNodeTree
{

private:
	BinaryNode<ItemType>* root;
public:
	// constructors and destructor:
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);// throw(NotFoundException);
	BinaryNodeTree(const ItemType& rootItem, BinaryNodeTree<ItemType>& leftTree, BinaryNodeTree<ItemType>& rightTree);// throw(NotFoundException);
	BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);// throw(NotFoundException);
	~BinaryNodeTree();

	int max(int a, int b) const;
	int getHeight() const;

	int getNumberOfNodes() const;

	// binary tree operations:
	bool isEmpty() const;

	ItemType getRootData() const
		throw(NotFoundException);
	void setRootData(const ItemType& newItem)
		throw(NotFoundException);

	void attachLeft(const ItemType& newItem)
		throw(NotFoundException);
	void attachRight(const ItemType& newItem)
		throw(NotFoundException);

	void attachLeftSubtree(BinaryNodeTree<ItemType>& leftTree)
		throw(NotFoundException);
	void attachRightSubtree(BinaryNodeTree<ItemType>& rightTree)
		throw(NotFoundException);

	void detachLeftSubtree(BinaryNodeTree<ItemType>& leftTree)
		throw(NotFoundException);
	void detachRightSubtree(BinaryNodeTree<ItemType>& rightTree)
		throw(NotFoundException);

	ItemType getLeftSubtree() const throw(NotFoundException);
	ItemType getRightSubtree() const
		throw(NotFoundException);

	void preorderTraverse(void visit(ItemType&))const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;
	



	// overloaded operator:
	BinaryNodeTree<ItemType>& operator = (const BinaryNodeTree<ItemType>& Item)
	{
		if (this != &Item)
		{
			destroyTree(root);  // deallocate left-hand side
			copyTree(Item.root, root);  // copy right-hand side
		}  // end if
		return *this;
	}  // end operator=



protected:
	BinaryNodeTree(BinaryNode<ItemType>* nodePtr);  // constructor

	int getHeightHelper(BinaryNode <ItemType> *subTreePtr) const;

	int getNumberOfNodesHelper(BinaryNode < ItemType >* subTreePtr) const;

	void copyTree(BinaryNode<ItemType>* treePtr, BinaryNode<ItemType>*& newTreePtr) const; //throw(NotFoundException);

	void destroyTree(BinaryNode<ItemType>* treePtr);

	// The next two methods retrieve and set the value
	// of the private data member root.

	BinaryNode<ItemType>* rootPtr() const;

	void setRootPtr(BinaryNode<ItemType>* newRoot);

	// The next two methods retrieve and set the values
	// of the left and right child pointers of a tree node.

	void getChildPtrs(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>*& leftChildPtr, BinaryNode<ItemType>*& rightChildPtr) const;
	void setChildPtrs(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* leftChildPtr, BinaryNode<ItemType>* rightChildPtr);


	void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

}; // end BinaryTree
// End of header file.


//#include <cstddef>  // definition of NULL


using namespace std;

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : root(nullptr)
{

}  // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)// throw(NotFoundException)
{
	//try
//{
		root = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
	//}
	//catch (bad_alloc e)
	//{
		//delete root;
		//throw NotFoundException("TreeException: constructor cannot allocate memory");
	//}  // end try
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem, BinaryNodeTree<ItemType>& leftTree, BinaryNodeTree<ItemType>& rightTree) //throw(NotFoundException)
{
	//try
	//{
		root = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
		assert(root != nullptr);
		attachLeftSubtree(leftTree);
		attachRightSubtree(rightTree);
	//}
	//catch (bad_alloc e)
	//{
		//delete root;
		//throw NotFoundException("TreeException: constructor cannot allocate memory");
	//}  // end try
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree)// throw(NotFoundException)
{
	//try
	//{
		copyTree(tree.root, root);
	//}
	//catch (bad_alloc e)
	//{
		//destroyTree(tree.root);
		//throw NotFoundException("TreeException: copy constructor cannot allocate memory");
	//}
	// end try
}  // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(BinaryNode<ItemType>* nodePtr) : root(nodePtr)
{

}  // end protected constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(root);
}  // end destructor


template<class ItemType>
 int BinaryNodeTree<ItemType>::max(int a, int b) const
{
	 if (a < b)
		 return b;
	 else
		 return a;
}



template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(root);
}


template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return  getNumberOfNodesHelper(root);
}



template<class ItemType>
bool  BinaryNodeTree<ItemType>::isEmpty() const
{
	return (root == nullptr);
}  // end isEmpty

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
throw(NotFoundException)
{
	if (isEmpty())
		throw NotFoundException("TreeException: Empty tree");
	return root->getItem();
}  // end getRootData

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem)
throw(NotFoundException)
{
	if (!isEmpty())
		root->setItem(newItem);
	else
	{
		try
		{
			root = new BinaryNode<ItemType>(newItem, nullptr, nullptr);
		}
		catch (bad_alloc e)
		{
			throw NotFoundException("TreeException: setRootData cannot allocate memory");
		} // end try
	}  // end if
}  // end setRootData

template<class ItemType>
void BinaryNodeTree<ItemType>::attachLeft(const ItemType& newItem)
throw(NotFoundException)
{

	if (isEmpty())
		throw NotFoundException("TreeException: Empty tree");
	else if (root->getLeftChildPtr() != nullptr)
		throw NotFoundException(
			"TreeException: Cannot overwrite left subtree");
	else  // Assertion: nonempty tree; no left child
	{
		try
		{
			BinaryNode<ItemType>* Tree = new BinaryNode<ItemType>(newItem, nullptr, nullptr);
			root->setLeftChildPtr(Tree);
		}
		catch (bad_alloc e)
		{
			throw NotFoundException("TreeException: attachLeft cannot allocate memory");
		}  // `end try
	}  // end if
}  // end attachLeft

template<class ItemType>
void BinaryNodeTree<ItemType>::attachRight(const ItemType& newItem)
throw(NotFoundException)
{
	if (isEmpty())
		throw NotFoundException("TreeException: Empty tree");
	else if (root->getRightChildPtr() != nullptr)
		throw NotFoundException("TreeException: Cannot overwrite right subtree");
	else  // Assertion: nonempty tree; no right child
	{
		try
		{
			BinaryNode<ItemType>* Tree = new BinaryNode<ItemType>(newItem, nullptr, nullptr);
			root->setRightChildPtr(Tree);
		}
		catch (bad_alloc e)
		{
			throw NotFoundException("TreeException: attachRight cannot allocate memory");
		}  // `end try
	}  // end if
}  // end attachRight

template<class ItemType>
void BinaryNodeTree<ItemType>::attachLeftSubtree(BinaryNodeTree<ItemType>& leftTree)
throw(NotFoundException)
{
	if (isEmpty())
		throw NotFoundException("TreeException: Empty tree");
	else if (root->getLeftChildPtr() != nullptr)
		throw NotFoundException(
			"TreeException: Cannot overwrite left subtree");
	else  // Assertion: nonempty tree; no left child
	{
		root->setLeftChildPtr(leftTree.root);
		leftTree.root = nullptr;
	}  // end if
}  // end attachLeftSubtree

template<class ItemType>
void BinaryNodeTree<ItemType>::attachRightSubtree(BinaryNodeTree<ItemType>& rightTree)
throw(NotFoundException)
{
	if (isEmpty())
		throw NotFoundException("TreeException: Empty tree");
	else if (root->getRightChildPtr() != nullptr)
		throw NotFoundException(
			"TreeException: Cannot overwrite right subtree");
	else  // Assertion: nonempty tree; no right child
	{
		root->setRightChildPtr(rightTree.root);
		rightTree.root = nullptr;
	}  // end if
}  // end attachRightSubtree

template<class ItemType>
void BinaryNodeTree<ItemType>::detachLeftSubtree(BinaryNodeTree<ItemType>& leftTree)
throw(NotFoundException)
{
	if (isEmpty())
		throw NotFoundException("TreeException: Empty tree");
	else
	{
		leftTree = BinaryNodeTree(root->getLeftChildPtr());
		root->getLeftChildPtr() = nullptr;
	}  // end if
}  // end detachLeftSubtree

template<class ItemType>
void BinaryNodeTree<ItemType>::detachRightSubtree(BinaryNodeTree<ItemType>& rightTree)
throw(NotFoundException)
{
	if (isEmpty())
		throw NotFoundException("TreeException: Empty tree");
	else
	{
		rightTree = BinaryNodeTree(root->getRightChildPtr());
		root->getRightChildPtr() = nullptr;
	}
}  // end detachRightSubtree

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getLeftSubtree() const
throw(NotFoundException)
{
	BinaryNode<ItemType>* subTreePtr;

	if (isEmpty())
		return BinaryNodeTree();
	else
	{
		copyTree(root->getLeftChildPtr(), subTreePtr);
		return BinaryNodeTree(subTreePtr);
	}
}  // end getLeftSubtree

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRightSubtree() const
throw(NotFoundException)
{
	BinaryNode<ItemType>* subTreePtr;

	if (isEmpty())
		return BinaryNodeTree();

	else
	{
		copyTree(root->getRightChildPtr(), subTreePtr);
		return BinaryNodeTree(subTreePtr);
	}

}  // end getRightSubtree

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&))const
{
	preorder(visit, root);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	inorder(visit, root);
}  // end inorderTraverse


template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	postorder(visit, root);
}


template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType> *subTreePtr) const
	{
		if (subTreePtr == nullptr)
			return 0;
		else
		{
			int maximum=0;
			maximum=max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
			return 1 + maximum;
		}
	}  // end getHeightHelper


template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType> * subTreePtr) const {
		if (subTreePtr == nullptr)
			return 0;
		else
			return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())+ getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
	}  // end getNumberOfNodesHelper




template<class ItemType>
void BinaryNodeTree<ItemType>::copyTree(BinaryNode<ItemType>* treePtr, BinaryNode<ItemType>*& newTreePtr) const// throw(NotFoundException)
{

	//BinaryNode<ItemType>* newTreePtr = nullptr;
	   // preorder traversal
	if (treePtr != nullptr)
	{  // copy node
		//try
		//{
			newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
			copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
			copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
		}
		//catch (bad_alloc e)
		//{
			//throw NotFoundException("TreeException: copyTree cannot allocate memory");
		//}  // `end try
	//}
	else
		newTreePtr = nullptr;  // copy empty tree
}  // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* treePtr)
{	    // postorder traversal
	if (treePtr != nullptr)
	{
		destroyTree(treePtr->getLeftChildPtr());
		destroyTree(treePtr->getRightChildPtr());
		delete treePtr;
		treePtr = nullptr;
	}  // end if
		 // end if
}  // end destroyTree

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::rootPtr() const
{
	return root;
}  // end rootPtr

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootPtr(BinaryNode<ItemType>* newRoot)
{
	root = newRoot;
}  // end setRoot

template<class ItemType>
void BinaryNodeTree<ItemType>::getChildPtrs(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>*& leftPtr, BinaryNode<ItemType>*& rightPtr) const
{
	leftPtr = nodePtr->getLeftChildPtr();
	rightPtr = nodePtr->getRightChildPtr();
}  // end getChildPtrs

template<class ItemType>
void BinaryNodeTree<ItemType>::setChildPtrs(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr)
{
	nodePtr->getLeftChildPtr() = leftPtr;
	nodePtr->getRightChildPtr() = rightPtr;
}  // end setChildPtrs

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

#endif
