//
// Created by Brandon on 3/3/2022.
//

#ifndef LAB7_BST_NODE_H
#define LAB7_BST_NODE_H

#include "NodeInterface.h"

struct Node : public NodeInterface
{
	friend class BST;

	explicit Node(int newVal) : value(newVal), left(nullptr), right(nullptr) {};

	~Node() override;

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const override;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface* getLeftChild() const override;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface* getRightChild() const override;

	bool hasLeft()
	{
		return (left != nullptr);
	}
	bool hasRight()
	{
		return (right != nullptr);
	}
	

private:
	int value;
	Node * left, *right;
};


#endif //LAB7_BST_NODE_H
