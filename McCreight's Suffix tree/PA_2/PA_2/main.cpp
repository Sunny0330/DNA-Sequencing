/********************************
	Alexander Lao
	11481444
	CptS 471
	Programming Assignment Two
*********************************/

#include "Parse.h"
#include "SuffixTree.h"

int main(int argc, char *argv[])
{
	// check for valid input
	if (argc != 3) printErrorMessage();

	string inputFileName = argv[1];
	string alphabetFileName = argv[2];
	string sequences[2];	// [name, sequence]
	string alphabet;

	// parse the sequence and alphabet
	parseAlphabetFile(alphabetFileName, alphabet);
	parseInputFile(inputFileName, sequences);

	//create suffix tree for user
	SuffixTree *userST = new SuffixTree();
	userST->constructTree(sequences[1],alphabet);


}