#include <stdio.h>
#define SIZE 100

int size(char*);
int countSentences(char*, char*);

void main() {

	char delimeters[] = { '.', '?', '!', '\0'};
	char string[SIZE];

	printf("Enter a string : ");
	gets(string);

	int count = countSentences(string, delimeters);

	printf(count == 1 ? "1 counted sentence\n" : "%d counted sentences\n", count);
}

int size(char* string) {

	int count = 0;
	while (string[count] != '\0') {

		count++;
	}
	return count;
}

int countSentences(char* string, char* delimiters) {

	int countSen = 0;
	int i = 0;
	int sizeArr = size(delimiters);

	while (string[i] != '\0') {

		for (int j = 0; j < sizeArr; j++) {

			if (string[i] == delimiters[j]) {

				countSen++;
				break;
			}
		}

		i++;
	}

	return countSen;
}