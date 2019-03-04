/*	Project:    P2 FrankenMap
	Name:       Kat Ottman
    Partner:    Darryl McCottrell
    Class:      CSC 1820 Section 1
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Node // creating a class that's variables will have two pieces of data
{
  public:
	int frequency;
	Node() { frequency = 1; }
	vector<int> appears_on_lines;
};

int main(int argc, char *argv[])
{
	map<string, Node> words;
	int countLine = 1;

	if (argc < 2)
	{
		cerr << "Must provide a file name" << endl;
		return 0;
	}

	ifstream infile(argv[1]);
	if (infile.is_open())
	{
		string line;

		while (getline(infile, line)) //adding pairs based on text file lines to map
		{
			Node n;

			auto it = words.find(line);
			if ((*it) == words.at(line)) //if line exists in map
			{
				n = (*it).second;
				n.frequency++;
			}
			else
			{
				n = Node();
			}

			n.appears_on_lines.push_back(countLine); //This line and the next comment work if there is only one occurence of each individual word
			words.emplace(line, n);
			countLine++;
		}

		infile.close();
	}
	else
	{
		cerr << "Unable to open file: " << argv[1] << endl;
	}
	//creating a loop to assure program doesn't stop after one search through map
	string word = "";
	cout << "Enter a word (case sensitive): ";

	while (getline(cin, word))
	{
		auto it = words.find(word);

		if (it == words.end())
		{
			cerr << "Word could not be found." << endl;
		}
		else //printing out word finding result
		{
			cout << word << " found " << (*it).second.frequency << " time(s) on lines: " << endl;
			//frequency doesn't work unless there's only one occurence of the word

			for (size_t positionInVector = 0; positionInVector < (*it).second.appears_on_lines.size(); positionInVector++) //print out lines where word appears in map
			{

				cout << (*it).second.appears_on_lines.at(positionInVector);
				if (positionInVector != ((*it).second.appears_on_lines.size() - 1)) //getting rid of trailing comma
				{
					cout << ", ";
				}
				else
				{
					cout << "\n";
				}
			}
		}
		cout << "Enter a word (case sensitive): " << endl;
	}
	return 0;
}