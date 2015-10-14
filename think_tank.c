/*
	Name: Soryung Lee(csddochi)
	Objectives: The program for generating three random numbers and
			printing the three words asociated with the corresponding numbers.
	Program Name: think tank (The Think Tank of Edward de Bono)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 25457 // last index of the word in noun.txt

int main(int argc, char** argv) 
{
	char word[128] = { 0, };
	int num[3] = { 0, };
	int i, temp;
	FILE* fp = fopen("noun.txt", "r");
	// Download the original version of noun.txt 
	//	in National Institute of the Korean Language.
	// This file is processed according to 
	//	the 'substantives_detail.txt' file by me.
	int this_index = 0;
	int get_index = 0;

	// A part for generating three random numbers except overlap
	srand((unsigned int)time(NULL)); // for avoiding c4244 warning
	num[0] = rand() % MAX;
	for (;;) { 
		num[1] = rand() % MAX;
		num[2] = rand() % MAX;
		if (num[1] == num[0])
			num[1] = rand() % MAX;
		if (num[2] == num[0])
			num[2] = rand() % MAX;
		if (num[2] == num[1])
			num[2] = rand() % MAX;
		if (num[0] != num[1] && num[0] != num[2])
			break;
	}

	// A portion for arranging to the numbers in ascending order
	for (i = 0; i < 2; i++) {
		if (num[i] >= num[i + 1]) {
			temp = num[i + 1];
			num[i + 1] = num[i];
			num[i] = temp;
		}
	}
	// A part for outputting the numbers in ascending
	printf("%d %d %d\n", num[0], num[1], num[2]);

	printf("<ThinkTank> There are today words:\n");
	while (!feof(fp)) // fp != EOF -> warning C4047
	{
		fscanf(fp, "%d %s", &get_index, word);
		
		if (get_index == num[this_index])
		{
			printf("%d %s\n", get_index, word), this_index++;
		}
		
		if (this_index == 3)
		{
			break; // while loop exit if print three words
		}
	}
}