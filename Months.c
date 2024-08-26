#include <stdio.h>
#define R 12
#define C 10

int getN();
void printM(char [][C], int n);

int size(char*);
char* findLongest(char[][C]);

void printWithGivenLetter(char[][C], char);

void toLower(char*);
void printWithoutGivenLetter(char[][C], char);

void printSomething(char months[][C]) {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (months[i][j] == 'a' || months[i][j] == 'A') {
				break;
			}
			else if (months[i][j] == '\0') {
				puts(months[i]);
				//break;
			}
		}
	}
}

void main() {

	char months[R][C] = {
		"January",
		"February",//8
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",//9
		"October",
		"November",
		"December"
	};

	int n = getN();
	printM(months, n);

	char* maxMonth = findLongest(months);
	printf("maxMonth: %s\n", maxMonth);

	printWithGivenLetter(months, 'd');

	printWithoutGivenLetter(months, 'A');

}

int getN() {

	int n;

	do {
		printf("Enter n: ");
		scanf_s("%d", &n);
	} while (n < 1 || n > 12);

	return n;
}

void printM(char months[][C], int n) {

	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", months[i]);

	printf("\n");

}

int size(char* string) {

	int count = 0;
	while (string[count] != '\0')
		count++;

	return count;
}

char* findLongest(char months[][C]) {

	int maxSize = size(months[0]);
	int currentSize;
	char* maxMonth = months[0];

	for (int i = 1; i < R; i++) {

		currentSize = size(months[i]);
		if (currentSize > maxSize) {

			maxSize = currentSize;
			maxMonth = months[i];
		}
	}

	return maxMonth;

}

void toLower(char* letterAddress) {

	if (*letterAddress >= 'A' && *letterAddress <= 'Z')
		*letterAddress = *letterAddress + 32;
}

void printWithGivenLetter(char months[][C], char letter) {

	toLower(&letter);
	printf("\nMonths containing the letter %c/%c\n", letter, letter - 32);
	for (int i = 0; i < R; i++) {

		for (int j = 0; months[i][j] != '\0'; j++) 
			if (months[i][j] == letter || months[i][j] == letter - 32) {

				printf("%s\n", months[i]);
				break;
			}
	}

	printf("\n");
}


void printWithoutGivenLetter(char months[][C], char letter) {

	toLower(&letter);
	printf("\nMonths without the letter %c/%c\n", letter, letter - 32);

	int flag;
	for (int i = 0; i < R; i++) {

		flag = 0;
		for(int j = 0; months[i][j] != '\0'; j++)
			if (months[i][j] == letter || months[i][j] == letter - 32) {

				flag = 1;
				break;
			}

		if (flag == 0)
			printf("%s\n", months[i]);
	}
}
