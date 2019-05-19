// string_task_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

#pragma warning(disable : 4996)

#define MAXLEN 100

char* substring(char* string, int position, int length);
void processFile(FILE* fi);
void iterate_word_container(std::vector<std::string> const&);


int main(void)
{
	char wordData[] = "inputFile.txt";
	char* sub_string;
	int position = 1;
	int length = 3;
	int len_of_word;
	int temp;

	FILE* fi = fopen(wordData, "r");
	if (fi == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	processFile(fi);

	return 0;
}

void processFile(FILE* fi)
{
	int i, j, count;
	char word[MAXLEN];
	char sorted_words[MAXLEN][MAXLEN];

	int const min_word_length = 4;
	int k = 0;

	std::vector<std::string> words;
	while (fscanf(fi, " %[^\n]s", word) != EOF)
	{
		j = 0;
		count = 0;

		char string_container[256];
		strcpy(string_container, word);

		char* ptr = strtok(string_container, " ");
		while (ptr)
		{
			if (strlen(ptr) >= min_word_length)
			{
				strcpy(sorted_words[k], ptr);
				words.push_back(ptr);
				++k;
			}
			ptr = strtok(NULL, " ");
		}
	}
	iterate_word_container(words);
}

void iterate_word_container(std::vector<std::string> const& words)
{

}

char* substring(char* string, int position, int length)
{
	char* pointer;
	int i;

	pointer = (char*)malloc(length + 1);
	if (pointer == NULL)
	{
		printf("Unable to allocate memory\n");
		exit(1);
	}

	for (i = 0; i < length; i++)
	{
		*(pointer + i) = *(string + position - 1);
		string++;
	}

	*(pointer + i) = '\0';

	return pointer;
}

