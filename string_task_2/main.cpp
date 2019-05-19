// string_task_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace
{
	int const Min_Word_Length = 4;
}

//char* substring(char* string, int position, int length);
void processFile(std::ifstream& file);
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
	if (token.length() >= Min_Word_Length)
	{
		words.push_back(token);
	}
}

void iterate_words_container(std::vector<std::string> const& words)
{
	
}
//
//char* substring(char* string, int position, int length)
//{
//	char* pointer;
//	int i;
//
//	pointer = (char*)malloc(length + 1);
//	if (pointer == NULL)
//	{
//		printf("Unable to allocate memory\n");
//		exit(1);
//	}
//
//	for (i = 0; i < length; i++)
//	{
//		*(pointer + i) = *(string + position - 1);
//		string++;
//	}
//
//	*(pointer + i) = '\0';
//
//	return pointer;
//}

