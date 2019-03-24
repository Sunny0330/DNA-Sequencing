/********************************
	Alexander Lao
	11481444
	CptS 471
	Programming Assignment Two
*********************************/

#include "Parse.h"

void parseInputFile(string fileName, string* sequences)
{
	string line;
	ifstream input;
	input.open(fileName);

	// check if the input file was opened successfully
	if (input)
	{
		// reading the sequence
		while (getline(input, line))
		{
			// reading the beginning of a new sequence
			if (line[0] == '>')
			{
				// read in the name
				sequences[0] = line.substr(1, line.find(' ') - 1);
			}
			// done once we hit the blank line
			else if (line == "") break;
			// otherwise concatenate the characters
			else sequences[1].append(line);
		}

		// append a '$' at the end
		sequences[1].append("$");
	}
	else
	{
		cout << "Unable to locate file: " << fileName << endl;
		exit(0);
	}
}

void parseAlphabetFile(string fileName, string &alphabet)
{
	string token;
	int i = 0;
	ifstream input;
	input.open(fileName);

	// check if the input file was opened successfully
	if (input)
	{
		// read the alphabet line and parse it based on the spaces
		while (getline(input, token, ' '))
		{
			// store the token
			alphabet.append(token);
		}


		//trim off the new line character that was appended at the end
		alphabet.pop_back();

		//add the '$' to the beggining because it has the highest precedence
		alphabet = "$" + alphabet;

	}


	else
	{
		cout << "Unable to locate file: " << fileName << endl;
		exit(0);
	}
}

void printErrorMessage()
{
	cout << "Invalid arguments! Please enter arguments in the form:" << endl;
	cout << "<executable name> <input file containing sequence s> " <<
			"<input alphabet file>" << endl;
	exit(0);
}