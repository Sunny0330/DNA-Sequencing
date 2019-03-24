#include "SuffixTree.h"

SuffixTree::SuffixTree(string newS, string newAlphabet)
{
	// store the string and alphabet
	this->s = newS;
	this->alphabet = newAlphabet;

	this->root = new Node();

	this->root->u = nullptr;
	this->root->v = this->root;
	this->root->children.resize(this->alphabet.length());
}

void SuffixTree::constructTree()
{

	Node * firstLeaf = new Node(this->root, 0, this->s.length() - 1, this->alphabet.length());


		//add first leaf
		this->root->children[this->alphabet.find(this->s[firstLeaf->uLabelStart])] = firstLeaf;
		
		//push_back(new Node(this->root, 0, this->s.length() - 1));


	// start at the first child of the root
		Node* currentNode = firstLeaf;


	// loop through the entire input string
	for (int i = 1; i < this->s.length(); i++)
	{
		currentNode = insertNode(i, currentNode);
		


	}


}


Node* SuffixTree::insertNode(int i, Node *currentNode)
{
	Node *SLu = currentNode->u->v;
	Node *uPrime = currentNode ->u->u;
	Node *returnNode = nullptr;

	
	

	// Case IA: SL(u) is known and u is not the root
	if ((SLu != nullptr) &&  (currentNode->u != this->root))
	{


	}
	// Case IB: SL(u) is known and u is the root
	else if ((SLu != nullptr) && (currentNode->u == this->root))
	{
		returnNode = FindPath(this->root, i);


	}
	// Case IIA: SL(u) is unknown and u' is not the root
	else if ((SLu == nullptr) && (uPrime != this->root))
	{

	}
	// Case IIB: SL(u) is unknown and u' is the root
	else if ((SLu != nullptr) && (uPrime == this->root))
	{

	}

	return returnNode;
}

Node* SuffixTree::FindPath (Node *nodePtr, int strPtr)
{
	

	for (int i =0; i < nodePtr->children.size(); i++)
	{
		



	}

	//make new node
	Node *newNode = new Node(nodePtr, strPtr, this->s.length() -1, this->alphabet.length());

	//add the children 
	nodePtr->children.push_back(newNode);

	return newNode;

}