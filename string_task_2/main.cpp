// string_task_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

namespace
{
	int const MIN_WORD_LEN = 4;
	size_t SUBSTR_LEN = 4;

}

void processFile(std::ifstream& file);
void result_print(std::map<std::string, int> const& map);
void fill_words_container(std::string const& token, std::vector<std::string>& words);
void iterate_words_container(std::vector<std::string> const&);

int main(void)
{
	std::string wordData = "inputFile.txt";
	std::ifstream fileHandler{ wordData };
	
	if (!fileHandler)
	{
		std::cout << "File is corrupted\n";
		return -1;
	}
	processFile(fileHandler);

	return 0;
}

void processFile(std::ifstream& file)
{
	std::vector<std::string> words;
	std::string line;
	std::string delimiter = " ";
	std::string token;
	while (std::getline(file, line, '\n'))
	{
		size_t pos = 0;
		while ((pos = line.find(delimiter)) != std::string::npos) 
		{
			token = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			fill_words_container(token, words);
		}
		if (line.length() != 0)
		{
			fill_words_container(line, words);
		}
	}
	iterate_words_container(words);
}

void fill_words_container(std::string const& token, std::vector<std::string>& words)
{
	if (token.length() >= MIN_WORD_LEN)
	{
		words.push_back(token);
	}
}

void iterate_words_container(std::vector<std::string> const& words)
{
	std::map<std::string, int> sorted_words;
	for (auto word = words.begin(); word != words.end(); ++word)
	{
		for (int i = 0; i < word->length(); ++i)
		{
			if (i + SUBSTR_LEN < word->length())
			{
				auto substr = word->substr(i, i + SUBSTR_LEN);
				if (word->find(substr) != std::string::npos)
				{
					sorted_words[substr]++;
				}
			}
		}
		sorted_words[*word]++;
	}
	result_print(sorted_words);
}

void result_print(std::map<std::string, int> const& map)
{
	for (auto p = map.begin(); p != map.end(); ++p)
	{
		std::cout << p->first << " = " << p->second << " times.\n";
	}
}

