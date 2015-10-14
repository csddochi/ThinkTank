#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 25457

int main(int argc, char** argv) {
	char word[1024] = { 0, };
	int num[3] = { 0, };
	int i, j, temp;
	FILE* f = 0;

	srand(time(NULL));
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

	//srand(time(NULL));
	//for (i = 0; i < 3; i++)
	//{
	//	num[i] = rand() % 10;
	//}
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 1; j < 3; j++)
	//	{
	//		if (num[i] == num[j])
	//		{
	//			num[i] = rand() % 10;
	//		}
	//	}
	//}


	for (i = 0; i < 2; i++) {
		if (num[i] > num[i + 1]) {
			temp = num[i + 1];
			num[i + 1] = num[i];
			num[i] = temp;
		}
	}

	printf("%d %d %d\n", num[0], num[1], num[2]);

	char ch;
	int this_index = 0;
	int get_index = 0;

	f = fopen("noun.txt", "r");

	while (f != EOF)
	{
		fscanf(f, "%d %s", &get_index, word);
		if (get_index == num[this_index])
			printf("%d %s\n", get_index, word), this_index++;
		if (this_index == 3)break;
	}
	//system("pause");
}