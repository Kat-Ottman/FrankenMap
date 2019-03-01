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

class Node
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

		while (getline(infile, line)) //adding pairs to words map
		{
			Node n = Node();

			words.emplace(line, n);
			//How do you access the line number for the word that the user enters?
			//How would you enter that into the vector so you can access the vector later?
		}

		infile.close();
	}
	else
	{
		cerr << "Unable to open file: " << argv[1] << endl;
	}

	string word;
	cout << "Enter a word (case sensitive): ";
	cin >> word;
	auto it = words.find(word);
	if (it == words.end())
	{
		cerr << "Word could not be found.";
	}
	else
	{
		cout << word << " found " << words.at(word).frequency << " times on lines: " << endl;
		for (int i = 0; i < words.at(word).appears_on_lines.size(); i++)
		{
			cout << words.at(word).appears_on_lines.at(i);
			//How do you print a list of the line numbers with commas without the trailing comma?
		}
	}
	return 0;
}