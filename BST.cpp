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
	return insertNode(root, data);
}

bool BST::insertNode(Node*& nodeToFind, int key)
{
	//nodeToFind = SearchBST(nodeToFind, key);
	if (nodeToFind == nullptr)
	{
		nodeToFind = new Node(key);
		return true;
	}
	else
	{
		if (key < nodeToFind->value)
		{
			return insertNode(nodeToFind->left, key);
		}
		else if (key > nodeToFind->value)
		{
			return insertNode(nodeToFind->right, key);
		}
		else
		{
			return false;
		}
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
	if (nodeToFind == nullptr)
	{
		cerr << "Value: " << key << " not found, failed to delete." << endl;
		return false;
	}
	else if (nodeToFind->value == key)
	{
		if (nodeToFind->hasLeft() && nodeToFind->hasRight())
		{ // yes both
			Node* largestLeftChild = nodeToFind->left;
			while (largestLeftChild->hasRight())
			{
				largestLeftChild = largestLeftChild->right;
			}
			nodeToFind->value = largestLeftChild->value;
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
	}
	else
	{
		if (key < nodeToFind->value)
		{
			return deleteNode(nodeToFind->left, key);
		}
		else if (key > nodeToFind->value)
		{
			return deleteNode(nodeToFind->right, key);
		}
		else
		{
			return false;
		}
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

//
//Node*& BST::SearchBST(Node*& currentNode, int key)
//{
//	//cout << "Finding " << key << " in tree..." << endl;
//
//	if (currentNode == nullptr)
//	{
//		//cout << "key value not found; returning nullptr" << endl;
//		return currentNode;
//	}
//	else if (key < currentNode->value)
//	{
//		//cout << "key < currentNode->value; moving left" << endl;
//		return SearchBST(currentNode->left, key);
//	}
//	else if (key > currentNode->value)
//	{
//		//cout << "key > currentNode->value; moving right" << endl;
//		return SearchBST(currentNode->right, key);
//	}
//	else // if key == value
//	{
//		//cout << "Node at " << key << " found; returning currentNode" << endl;
//		return currentNode;
//	}
//}
