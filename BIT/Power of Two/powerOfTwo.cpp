#include <stdio.h>
int number;
int isPowerOfTwo(int number) {
	if ((number - 1) & number) {
		return 0;
	} else {
		return 1;
	}
}
int main() {
	scanf("%d", &number);
	printf("%d", isPowerOfTwo(number));
}