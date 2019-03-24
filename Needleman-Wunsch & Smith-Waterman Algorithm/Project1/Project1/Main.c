/*
* Author:      Bryce Handerson (bhanderson)
*              Andrew M Bates (abates09 | andrewbates09)
* File:        test_mc_stree.cpp
* Project:     CptS 471 - Project 2
* Due:         April 04, 2014
*
* Notes:
* This is the testing driver for Project 2
*/

/* ---------- INCLUDES ---------- */

#include "tree.c"
#include "tree.h"

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

/* ---------- PROTOTYPES -------- */	// testing driver prototypes go here...

long long getMemUsage();

int validateArgs(const int argc, const char **argv);

Node * test_construction(void);
void test_dfs(Node *node);
void test_bwt(Node *node);

double double_time(struct timeval *atime);
double diff_time(struct timeval *tstart, struct timeval *tstop);

void cleanupTime(void);

/* ---------- DEFINITIONS ------- */

struct sysinfo memInfo;


// validate user input to continue, etc..
// return 0 for success, -1 for failure
int validateArgs(const int argc, const char **argv) {
	if (argc < 3) {
		printf("\nERROR: Please check your input.\n");
		printf("Format: <test executable> <input fasta> <input alphabet>\n\n");
		return -1;
	}

	printf("\nPlease verify the following information:\n\n");
	printf("Input File:\t%s\n", argv[1]);
	printf("Input Alph:\t%s\n", argv[2]);

	printf("\nIf any of this is wrong, press Ctrl+C to panic.\nOtherwise press ENTER to continue...");
	getchar();
	return (0);
}

//
int setUp(const char ** argv) {

	char inputname[64];
	char alphaname[64];

	struct stat input_st;
	struct stat alpha_st;

	stat(argv[1], &input_st);
	stat(argv[2], &alpha_st);

	unsigned int input_size = input_st.st_size;
	unsigned int alpha_size = alpha_st.st_size;

	strcpy(inputname, argv[1]);
	strcpy(alphaname, argv[2]);

	FILE *inputfile;
	FILE *alphafile;

	if ((inputfile = fopen(inputname, "r")) == NULL) {
		if (errno == ENOENT) {
			printf("\nERROR: No sequence file found.\n");
			return -1;
		}
		else {
			printf("\nERROR: Unhandled sequence read error.\n");
			return -1;
		}
	}

	if ((alphafile = fopen(alphaname, "r")) == NULL) {
		if (errno == ENOENT) {
			printf("\nERROR: No sequence file found.\n");
			return -1;
		}
		else {
			printf("\nERROR: Unhandled sequence read error.\n");
			return -1;
		}
	}

	ibuff = (char*)malloc(input_size);
	if (ibuff == NULL) {
		printf("\nERROR: Cannot allocate memory for sequence.\n");
		return -1;
	}

	abuff = (char*)malloc(alpha_size);
	if (abuff == NULL) {
		printf("\nERROR: Cannot allocate memory for alphabet.\n");
		return -1;
	}

	unsigned int i = 0;

	int ibytes = input_size;
	int abytes = alpha_size;
	char inchar = '\0';

	// read in name of sequence
	do {
		inchar = fgetc(inputfile);
		if (inchar == '>') {
			inchar = fgetc(inputfile);
			while (inchar != '\n'  && inchar == '|') {
				if (i < 15) {
					iname[i] = inchar;
					++i;
				}
				inchar = fgetc(inputfile);
			}
			iname[i] = '\0';
		}
	} while (inchar != '\n' && inchar != EOF);

	// read in the sequence and ++inputLen
	do {
		inchar = fgetc(inputfile);
		while (inchar != EOF) {
			if (inchar != ' ' && inchar != '\n') {
				ibuff[inputLen] = inchar;
				++inputLen;
				//++i;
				//ibytes--;
			}
			inchar = fgetc(inputfile);
		}
	} while (inchar != EOF); /*ibytes > 0 && */
	ibuff[inputLen] = '$';
	inputLen++;
	ibuff[inputLen] = '\0';

	// read in alphabet
	do {
		inchar = fgetc(alphafile);
		if (inchar != ' ' && inchar != '\n' && inchar != EOF) {
			abuff[alphabetLen] = inchar;
			++alphabetLen;
		}
	} while (abytes > 0 && inchar != EOF);
	abuff[alphabetLen] = '\0';

	fclose(inputfile);
	fclose(alphafile);

	return (0);
}


// run construction
Node * test_construction()
{
	// construct()
	return (suffixTree());
}

// run enumerate
void test_dfs(Node *node)
{
	// enumerate()
	int test = dfs(node);
	//return (0);
}

// run bwt
void test_bwt(Node *node)
{
	printf("\nBWT:\t");
	int test = bwt(node);
	printf("\n");
	//return (0);
}


// where it all starts
int main(int argc, const char *argv[])
{
	long long startMem, setupMem, constructMem, dfsMem, bwtMem = 0;

	Node *testTree;

	// call some data validation first
	if (validateArgs(argc, argv) < 0) {
		return -1;
	}

	// suffix tree construction


	testTree = test_construction();		// build ST


										// depth first search
	//test_dfs(testTree);
	printf("Max Depth: %d\n", maxDepth);
	getchar();

	// burrows wheeler transform
	printf("\nSEQ:\t");
	//for ( unsigned int it = 0; it < inputLen; ++it)
	//		printf("%c ", ibuff[it]);
	test_bwt(testTree);

	dfs(testTree);

	doNotBeLikeFirefox(testTree);


	//printf("PRAM:\t%llu\n", getPhysMem());
	//printf("VRAM:\t%llu\n", getVirtMem());

	return (0);
}