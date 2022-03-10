//
// Created by Brandon on 3/3/2022.
//

#ifndef LAB7_BST_BST_H
#define LAB7_BST_BST_H

#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface
{
protected:
	Node* root;

public:
	BST();

	~BST() override;

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface* getRootNode() const override;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data) override;

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data) override;

	bool BST::deleteNode(Node*& nodeToFind, int data);
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear() override;
	void BST::deleteTree(Node*& currentNode);

	//bool updateData(Node*& currentNode, int data);

	Node* BST::SearchBST(Node*& currentNode, int key);
};


#endif //LAB7_BST_BST_H
