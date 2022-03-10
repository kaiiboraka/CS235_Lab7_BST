//
// Created by Brandon on 3/3/2022.
//

#include "BST.h"

BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	BST::clear();
}

NodeInterface* BST::getRootNode() const
{
	return root;
}

bool BST::add(int data)
{
	Node* nodeToFind = SearchBST(root, data);
	if (nodeToFind == nullptr)
	{
		nodeToFind = new Node(data);
		
		return true;
	}
	// value already exists, can't add
	return false;
}

bool BST::remove(int data)
{
	return deleteNode(root, data);
}

bool BST::deleteNode(Node*& nodeToFind, int key)
{
	nodeToFind = SearchBST(nodeToFind, key);
	
	if(nodeToFind == nullptr)
	{
		cerr << "Value: " << key << " not found, failed to delete." << endl;
		return false;
	}
	else if (nodeToFind != nullptr)
	{
		if (nodeToFind->hasLeft() && nodeToFind->hasRight())
		{ // yes both
			Node* largestLeftChild = nodeToFind->left;
			while (largestLeftChild->right != nullptr)
			{
				largestLeftChild = largestLeftChild->right;
			}
			nodeToFind->value = largestLeftChild->getData();
			deleteNode(nodeToFind->left, nodeToFind->value);

			return true;
		}
		else if (nodeToFind->hasLeft() && !nodeToFind->hasRight())
		{ // left only : yes left no right
			Node* temp = nodeToFind->left;
			delete nodeToFind;
			nodeToFind = temp;
			return true;
		}
		else if (!nodeToFind->hasLeft() && nodeToFind->hasRight())
		{ // right only : no left yes right
			Node* temp = nodeToFind->right;
			delete nodeToFind;
			nodeToFind = temp;
			return true;
		}
		else if (!nodeToFind->hasLeft() && !nodeToFind->hasRight())
		{ // no neither
			delete nodeToFind;
			nodeToFind = nullptr;
			return true;
		}
		
		return true;
	}

	return false;
}

void BST::clear()
{
	deleteTree(root);
}

void BST::deleteTree(Node*& currentNode)
{
	if (currentNode != nullptr)
	{
		deleteTree(currentNode->left);
		deleteTree(currentNode->right);
		delete currentNode;
		currentNode = nullptr;
	}
}


Node* BST::SearchBST(Node*& currentNode, int key)
{
	if (currentNode == nullptr)
	{
		return nullptr;
	}
	else if (key < currentNode->getData())
	{
		return SearchBST(currentNode->left, key);
	}
	else if (key > currentNode->getData())
	{
		return SearchBST(currentNode->right, key);
	}
	else
	{
		return currentNode;
	}
}
