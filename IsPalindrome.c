#include <stdio.h>
#include <stdbool.h>
#define CAPACITY 50

int count(char*);
bool isPalindrome(char*);
void palindrome(char str[]);


void main() {

	char string[CAPACITY];
	printf("Enter a string: ");
	gets(string);

	printf("\"%s\" %s\n", string,
		isPalindrome(string) ? "is a palindrome" : "is not a palindrome");

	palindrome(string);
}

int count(char* string) {

	int count = 0;
	while (string[count] != '\0')
		count++;

	return count;
}

bool isPalindrome(char* string) {

	int size = count(string);

	for (int i = 0; i < size / 2; i++)
		if (string[i] != string[size - i - 1])
			return false;

	return true;
}

void palindrome(char str[]) {

	int length = strlen(str);
	int flag = 0;

	for (int i = 0; i < length / 2; i++) {
		if (str[i] != str[length - i - 1]) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		printf("%s is not a palindrome\n", str);
	}
	else {
		printf("%s is a palindrome\n", str);
	}
}