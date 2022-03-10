//
// Created by Brandon on 3/3/2022.
//

#include "Node.h"

Node::~Node()
{
	// TODO: might not need??

	delete left;
	delete right;

	left  = nullptr;
	right = nullptr;
}

int Node::getData() const
{
	return value;
}

NodeInterface* Node::getLeftChild() const
{
	//TODO: is this really necessary
	//return (left != nullptr) ? left : nullptr;
	return left;
}

NodeInterface* Node::getRightChild() const
{
	//TODO: or does this work too
	return right;
}
