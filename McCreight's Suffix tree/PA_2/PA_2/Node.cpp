#include "Node.h"

Node::Node()
{
	this->nodeID = idCounter++;
	this->v = nullptr;
	this->u = nullptr;
	this->uLabelStart = 0;
	this->uLabelEnd = 0;
	this->stringDepth = 0;
}


Node::Node(Node* newU, int newLabelStart, int newLabelEnd, int alphabetLength)
{
	this->nodeID = idCounter++;
	this->v = nullptr;
	this->u = newU;
	this->uLabelStart = newLabelStart;
	this->uLabelEnd = newLabelEnd;
	this->children.resize(alphabetLength);
	this->stringDepth = -1;




}