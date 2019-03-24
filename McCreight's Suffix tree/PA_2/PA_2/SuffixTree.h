#pragma once

#include "Node.h"

#include <string>

using std::string;

class SuffixTree
{
	public:
		SuffixTree(string newS, string newAlphabet);
		void constructTree();
		Node* insertNode(int i, Node *currentNode);
		Node* FindPath(Node *nodePtr, int strPtr);

	private:
		string s;
		string alphabet;
		Node *root;
};