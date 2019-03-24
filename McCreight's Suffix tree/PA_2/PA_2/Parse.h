/********************************
	Alexander Lao
	11481444
	CptS 471
	Programming Assignment Two
*********************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

void parseInputFile(string fileName, string* sequences);
void parseAlphabetFile(string fileName, string &alphabet);
void printErrorMessage();