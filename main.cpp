/*	Project:    P2 FrankenMap
	Name:       Kat Ottman
    Partner:    PARTNER'S NAME IF ANY
    Class:      CSC 1820 Section 1
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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
			Node n = Node();

			words.emplace(line, n);
			//How do you access the line number for the word that the user enters?
			//How would you enter that into the vector so you can access the vector later?
			//always do this after implace
			//create an integer that will add every time a new line is made
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
			cout << word << " found " << words.at(word).frequency << " times on lines: " << endl;
			for (size_t positionInVector = 0; positionInVector < words.at(word).appears_on_lines.size(); positionInVector++) //print out lines where word appears in map
			{

				cout << words.at(word).appears_on_lines.at(positionInVector);
				if (positionInVector != (words.at(word).appears_on_lines.size() - 1)) //getting rid of trailing comma
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