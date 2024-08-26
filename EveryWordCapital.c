#include <stdio.h>
#define SIZE 100

int size(char*);
void turnEveryWordCapital(char*);

void main() {

	char string[SIZE];

	printf("Enter a string: ");
	gets(string);
	printf("\nThe string you entered \"%s\"\n\n", string);

	turnEveryWordCapital(string);

	printf("After turning every word capital the string is \"%s\"\n", string);
}

int size(char* string) {

	int count = 0;
	while (string[count] != '\0')
		count++;

	return count;
}

void turnEveryWordCapital(char* string) {

	int sizeWords = size(string);

	if (string[0] >= 'a' && string[0] <= 'z')
		string[0] -= 32;

	for (int i = 1; i < sizeWords - 1; ) {

		if (string[i] == ' ') {

			if (string[i + 1] >= 'a' && string[i + 1] <= 'z')
				string[i + 1] -= 32;

			i += 2;
		}

		i++;
	}
}