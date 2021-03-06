/*
* Author:      Bryce Handerson (bhanderson)
*              Andrew M Bates (abates09 | andrewbates09)
* File:        mc_stree.h
* Project:     CptS 471 - Project 2
* Due:         April 04, 2014
*
* Notes:
* The goal of this project is to implement the McCreight's suffix tree con-
*      struction algorithm, given an input string s (in the FASTA file format)
*      and a file containing the input alphabet.
*/

#ifndef _MC_STREE_H_
#define _MC_STREE_H_


/* ---------- INCLUDES ---------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ---------- DEFINITIONS ------- */

unsigned int alphabetLen = 0;
unsigned int inputLen = 0;
unsigned int inodes = 0;
unsigned int leafs = 1;
unsigned int maxDepth = 0;

char *abuff;
char *ibuff;
char iname[16];

typedef int bool;
enum { false, true };		// get mad, this is worth it


typedef struct Node {		// ananth complete
	unsigned int id;
	unsigned int depth;
	unsigned int numChildren;
	unsigned int suffixHead;
	unsigned int suffixTail;
	struct Node *parent;
	struct Node *suffixLink;
	struct Node **children;
}Node;


/* ---------- PROTOTYPES -------- */

int addChild(Node *parent, Node *child);

Node *makeNode(unsigned int id, Node *parent,
	unsigned int suffixHead, unsigned int suffixTail, unsigned int Depth);

Node *matchChild(Node *n, unsigned int suffix, unsigned int *i);

Node *splitEdge(Node *current, unsigned int head, unsigned int tail);

Node *ananthFindPath(Node *v, unsigned int head);

Node *ananthNodeHops(Node *vPrime, Node *u, unsigned int bHead,
	unsigned int bTail, unsigned int suffix);

int identifyCase(Node *root, Node *u);

Node *nodeHop(Node *n, unsigned int head, unsigned int tail);

Node *insert(unsigned int i, Node *root, Node *leaf);

Node *suffixTree(void);

int dfs(Node *node);

int bwt(Node *node);

void doNotBeLikeFirefox(Node *node);

#endif	// _MC_STREE_H_