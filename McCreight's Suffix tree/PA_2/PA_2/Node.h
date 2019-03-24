/********************************
	Alexander Lao
	11481444
	CptS 471
	Programming Assignment Two
*********************************/

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

static int idCounter = 0;

class SuffixTree;

class Node
{
	friend class SuffixTree;

	public:
		Node();
		Node(Node* newU, int newLabelStart, int newLabelEnd, int alphabetLength); 

	private:
		int nodeID;					// node ID
		Node *v;					// suffix-link pointer
		Node *u;					// parent pointer
		int uLabelStart;			// parent edge label starting index with respect to the string
		int uLabelEnd;				// parent edge label ending index with respect to the string
		vector<Node*> children;		// children pointers
		int stringDepth;			// string depth
};